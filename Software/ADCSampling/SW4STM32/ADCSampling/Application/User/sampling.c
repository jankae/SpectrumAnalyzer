#include "sampling.h"
#include "log.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm.h"
#include <math.h>

#define MAX_SAMPLING_LENGTH  	30000
static int32_t data1[MAX_SAMPLING_LENGTH / 2];
static int32_t data2[MAX_SAMPLING_LENGTH / 2];

static float window_data[MAX_SAMPLING_LENGTH];

extern TIM_HandleTypeDef htim8;
extern DMA_HandleTypeDef hdma_tim8_up;
extern DMA_HandleTypeDef hdma_tim8_ch4_trig_com;

typedef enum {
	FFT_WINDOW_RECTANGLE = 0,
	FFT_WINDOW_HANN = 1,
	FFT_WINDOW_HAMMING = 2,
	FFT_WINDOW_FLATTOP = 3,
	FFT_WINDOW_MAX = 4,
} fft_window_t;

static fft_window_t window_type = FFT_WINDOW_MAX;
static uint32_t fft_length = 0;

static float window_ampl_corr[FFT_WINDOW_MAX] = {
		1.0f,
		2.0f,
		1.84f,
		4.638f,
};

static float get_window_point(uint32_t index, uint32_t npoints,
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
	return normalized;
//	int32_t ret = normalized * 32768 + 0.5f;
//	if (ret > INT16_MAX) {
//		ret = INT16_MAX;
//	} else if (ret < INT16_MIN) {
//		ret = INT16_MIN;
//	}
//	return ret;
}

static void compute_window(float *dest, uint32_t npoints, fft_window_t window) {
	for (uint32_t i = 0; i < npoints; i++) {
		dest[i] = get_window_point(i, npoints, window);// * window_ampl_corr[window];
	}
}

float calc_fft(int32_t *d1, int32_t *d2, uint32_t npoints,
		float *window_data) {
	int64_t imag = 0, real = 0;
	for (uint32_t i = 0; i < npoints / 2; i++) {
		int32_t val = (d1[i] - 8192) * window_data[i * 2];
		int64_t buf = imag;
		imag = -real;
		real = val + buf;
		val = (d2[i] - 8192) * window_data[i * 2 + 1];
		buf = imag;
		imag = -real;
		real = val + buf;
	}
	float peak = sqrt(imag * imag + real * real) * window_ampl_corr[window_type]
			/ (npoints / 2);
	float vPeak = peak / 8192;
	float l = log10(vPeak);
	float dbm = 10 + 20 * l;
	return dbm;
}

float sampling_get_dbm(uint32_t npoints) {
	if (npoints > MAX_SAMPLING_LENGTH) {
		return NAN;
	}
	// adjust window if necessary
	if (npoints != fft_length || window_type != FFT_WINDOW_FLATTOP) {
		fft_length = npoints;
		window_type = FFT_WINDOW_FLATTOP;
		compute_window(window_data, fft_length, window_type);
	}

	HAL_StatusTypeDef res = HAL_OK;
	// start sampling
	res |= HAL_DMA_Start(&hdma_tim8_up, (uint32_t) &(GPIOF->IDR), (uint32_t) data2,
			npoints / 2);
	res |= HAL_DMA_Start(&hdma_tim8_ch4_trig_com, (uint32_t) &(GPIOF->IDR),
			(uint32_t) data1, npoints / 2);
	/* Enable the TIM Update DMA request */
	__HAL_TIM_ENABLE_DMA(&htim8, TIM_DMA_UPDATE | TIM_DMA_CC4);
	uint32_t start = HAL_GetTick();
	res |= HAL_TIM_Base_Start(&htim8);
	if (res != HAL_OK) {
		LOG(Log_Sampling, LevelWarn, "Failed to start ADC sampling");
		HAL_DMA_Abort(&hdma_tim8_ch4_trig_com);
		HAL_DMA_Abort(&hdma_tim8_up);
		HAL_TIM_Base_Stop(&htim8);
		return NAN;
	}
	res = HAL_DMA_PollForTransfer(&hdma_tim8_up,
			HAL_DMA_FULL_TRANSFER, 1000);
	res |= HAL_DMA_PollForTransfer(&hdma_tim8_ch4_trig_com, HAL_DMA_FULL_TRANSFER,
			100);
	uint32_t stop = HAL_GetTick();
	if (res != HAL_OK) {
		LOG(Log_Sampling, LevelWarn, "Timed out while sampling ADC");
		HAL_DMA_Abort(&hdma_tim8_ch4_trig_com);
		HAL_DMA_Abort(&hdma_tim8_up);
		HAL_TIM_Base_Stop(&htim8);
		return NAN;
	}
	HAL_TIM_Base_Stop(&htim8);
	LOG(Log_Sampling, LevelDebug, "Got %lu samples in %lums", npoints,
			stop - start);

	float fft = calc_fft(data1, data2, npoints, window_data);
	LOG(Log_Sampling, LevelInfo, "FFT result: %2.2f", fft);

	return fft;
}

void sampling_test() {
	log_init();
	LOG(Log_Sampling, LevelInfo, "Start");
	compute_window(window_data, MAX_SAMPLING_LENGTH, FFT_WINDOW_FLATTOP);
	while (1) {
		HAL_Delay(5);
		HAL_DMA_Start(&hdma_tim8_up, (uint32_t) &(GPIOF->IDR), (uint32_t) data2,
		MAX_SAMPLING_LENGTH / 2);
		HAL_DMA_Start(&hdma_tim8_ch4_trig_com, (uint32_t) &(GPIOF->IDR), (uint32_t) data1,
		MAX_SAMPLING_LENGTH / 2);
		/* Enable the TIM Update DMA request */
		__HAL_TIM_ENABLE_DMA(&htim8, TIM_DMA_UPDATE | TIM_DMA_CC4);
		uint32_t start = HAL_GetTick();
		HAL_TIM_Base_Start(&htim8);
//		while(1);
		HAL_StatusTypeDef res = HAL_DMA_PollForTransfer(&hdma_tim8_up,
				HAL_DMA_FULL_TRANSFER, 1000);
		res = HAL_DMA_PollForTransfer(&hdma_tim8_ch4_trig_com, HAL_DMA_FULL_TRANSFER,
				100);
		uint32_t stop = HAL_GetTick();
		if (res != HAL_OK) {
			LOG(Log_Sampling, LevelWarn, "Timed out while sampling ADC");
			HAL_DMA_Abort(&hdma_tim8_ch4_trig_com);
			HAL_DMA_Abort(&hdma_tim8_up);
			HAL_TIM_Base_Stop(&htim8);
			continue;
		}
		HAL_TIM_Base_Stop(&htim8);
		LOG(Log_Sampling, LevelDebug, "Got %lu samples in %lums", MAX_SAMPLING_LENGTH,
				stop - start);

		float fft = calc_fft(data1, data2, MAX_SAMPLING_LENGTH, window_data);
		LOG(Log_Sampling, LevelInfo, "FFT result: %2.2f", fft);
		vTaskDelay(30);
	}
}
