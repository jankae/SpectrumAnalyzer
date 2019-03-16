#include "FFTSampling.h"

#include <math.h>
#include "stm.h"
#include "log.h"
#include "DummyData.h"

#define STATUS_ENABLED		0x01
#define STATUS_BUSY			0x02

#define WINDOW_BASE_ADDR	0x4000
#define WINDOW_MAX_POINTS	8192

static fft_window_t programmed_window;
static uint16_t programmed_window_points = 0;

static float window_ampl_corr[FFT_WINDOW_MAX] = {
		1.0f,
		2.0f,
		1.85f,
		4.638f,
};

typedef struct {
	uint16_t status;
	uint16_t pointsPerCoefficient;
	uint32_t npoints;
	int64_t res_real;
	int64_t res_imag;
}__attribute__((packed)) fpga_control_t;


extern SPI_HandleTypeDef hspi1;
static uint16_t read16(uint16_t address) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[2] = { address & 0x7FFF, 0 };
	uint16_t rec[2];
	HAL_SPI_TransmitReceive(&hspi1, (uint8_t*) send, (uint8_t*) rec, 2, 10);
	HAL_Delay(2);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
//	LOG(Log_FFT, LevelDebug, "Read 0x%04x from 0x%04x", rec[1], address);
	return rec[1];
}
static void write16(uint16_t address, uint16_t val) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[2] = { address | 0x8000, val };
	HAL_SPI_Transmit(&hspi1, (uint8_t*) send, 2, 10);
	HAL_Delay(2);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
//	LOG(Log_FFT, LevelDebug, "Write 0x%04x to 0x%04x", val, address);
}
static uint32_t read32(uint16_t address) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[3] = { address & 0x7FFF, 0, 0 };
	uint16_t rec[3];
	HAL_SPI_TransmitReceive(&hspi1, (uint8_t*) send, (uint8_t*) rec, 3, 10);
	HAL_Delay(2);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	LOG(Log_FFT, LevelDebug, "Read 0x%08x from 0x%04x", rec[2] << 16 | rec[1], address);
	return rec[2] << 16 | rec[1];
}
static void write32(uint16_t address, uint32_t val) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[3] = { address | 0x8000, val & 0xFFFF, val >> 16 };
	HAL_SPI_Transmit(&hspi1, (uint8_t*) send, 3, 10);
	HAL_Delay(2);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	LOG(Log_FFT, LevelDebug, "Write 0x%08x to 0x%04x", val, address);
}
static uint64_t read64(uint16_t address) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[5] = { address & 0x7FFF, 0, 0, 0, 0 };
	uint16_t rec[5];
	HAL_SPI_TransmitReceive(&hspi1, (uint8_t*) send, (uint8_t*) rec, 5, 10);
	HAL_Delay(2);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	uint64_t res;
	memcpy((uint8_t*) &res, (uint8_t*) &rec[1], 8);
	return res;
}
static void write64(uint16_t address, uint64_t val) {
//	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[5] = { address | 0x8000, val & 0xFFFF, (val >> 16) & 0xFFFF,
			(val >> 32) & 0xFFFF, val >> 48 };
	HAL_SPI_Transmit(&hspi1, (uint8_t*) send, 5, 10);
	HAL_Delay(2);
//	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
}
static int16_t get_window_point(uint16_t index, uint16_t npoints,
		fft_window_t window) {
	float normalized = 0;
	switch (window) {
	case FFT_WINDOW_RECTANGLE:
		normalized = 1.0f;
		break;
	case FFT_WINDOW_HANN:
		normalized = 0.5f * (1 - cos(2.0f * M_PI * index / (npoints - 1)));
		break;
	case FFT_WINDOW_HAMMING:
		normalized = 0.5434782609f
				- (1 - 0.5434782609f) * cos(2 * M_PI * index / (npoints - 1));
		break;
	case FFT_WINDOW_FLATTOP:
		normalized = 0.21557895f
				- 0.41663158 * cos(2.0f * M_PI * index / (npoints - 1))
				+ 0.277263158 * cos(4.0f * M_PI * index / (npoints - 1))
				- 0.083578947 * cos(6.0f * M_PI * index / (npoints - 1))
				+ 0.006947368 * cos(8.0f * M_PI * index / (npoints - 1));
		break;
	}
	int32_t ret = normalized * 32768 + 0.5f;
	if (ret > INT16_MAX) {
		ret = INT16_MAX;
	} else if (ret < INT16_MIN) {
		ret = INT16_MIN;
	}
	return ret;
}
static void program_window(uint16_t points, fft_window_t window) {
	if (points == programmed_window_points && window == programmed_window) {
		// already the correct window in the FPGA, nothing to do
		return;
	}

	for(uint16_t i=0;i<points;i++) {
		write16(WINDOW_BASE_ADDR + i, get_window_point(i, points, window));
	}

	programmed_window_points = points;
	programmed_window = window;
}

uint32_t FFT_take_sample(uint32_t points, fft_window_t window, uint32_t dummyFreq) {
	uint16_t div = (points + WINDOW_MAX_POINTS - 1) / WINDOW_MAX_POINTS;
	uint16_t window_points = (points + div - 1) / div;

	// stop any ongoing operation
	write16(0x00, 0x00);

	LOG(Log_FFT, LevelDebug, "Window pts: %u, per FFT pt: %u", window_points, div);

	program_window(window_points, window);

	write16(0x01, div - 1);
	read16(0x01);
	write32(0x02, points);
	read32(0x02);
	write16(0x00, STATUS_ENABLED);

	if(dummyFreq) {
		if(!(read16(0x00) & STATUS_BUSY)) {
			LOG(Log_FFT, LevelWarn, "Not busy before generating dummy data");
		}
		generate_dummy_data(dummyFreq, 8000, points + 1, 0.0f);
		if (read16(0x00) & STATUS_BUSY) {
			LOG(Log_FFT, LevelWarn, "Still busy after generating dummy data");
		}
	} else {
		while(read16(0x00) & STATUS_BUSY);
	}

	int64_t raw_real = read64(0x04);
	int64_t raw_imag = read64(0x08);

	LOG(Log_FFT, LevelDebug, "Result: raw_real: %09ld%ld, raw_imag: %09ld%ld", raw_real/1000000, raw_real%1000000, raw_imag/1000000, raw_imag%1000000);

	int32_t real = raw_real / (32768UL * (points / 2));
	int32_t imag = raw_imag / (32768UL * (points / 2));

	write16(0x00, 0x00);

	LOG(Log_FFT, LevelInfo, "Result: real: %ld, imag: %ld", real, imag);

	uint32_t abs = window_ampl_corr[window] * sqrt(real * real + imag * imag);
	return abs;
}

void fft_spi_mem_test() {
#define TEST_ITERATIONS			100
	uint16_t fail = 0, pass = 0;
	for(uint16_t i=0;i<TEST_ITERATIONS;i++) {
		write16(0x01, i);
		if(read16(0x01) != i) {
			fail++;
		} else {
			pass++;
		}
		vTaskDelay(5);
	}
	LOG(Log_FFT, LevelInfo, "SPI mem test: %d passed, %d failed", pass, fail);
}

