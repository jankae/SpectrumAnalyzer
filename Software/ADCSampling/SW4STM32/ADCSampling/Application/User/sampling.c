#include "sampling.h"
#include "log.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm.h"
#include <math.h>

#define SAMPLING_LENGTH  	30000
static int32_t data1[SAMPLING_LENGTH / 2];
static int32_t data2[SAMPLING_LENGTH / 2];

static float window_data[SAMPLING_LENGTH];

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
	float peak = sqrt(imag * imag + real * real)
			* window_ampl_corr[FFT_WINDOW_FLATTOP] / (npoints / 2);
	float vPeak = peak / 8192;
	float l = log10(vPeak);
	float dbm = 10 + 20 * l;
	return dbm;
}

void sampling_start() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");
	compute_window(window_data, SAMPLING_LENGTH, FFT_WINDOW_FLATTOP);
	while (1) {
		HAL_Delay(5);
		HAL_DMA_Start(&hdma_tim8_up, (uint32_t) &(GPIOF->IDR), (uint32_t) data2,
		SAMPLING_LENGTH / 2);
		HAL_DMA_Start(&hdma_tim8_ch4_trig_com, (uint32_t) &(GPIOF->IDR), (uint32_t) data1,
		SAMPLING_LENGTH / 2);
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
			LOG(Log_App, LevelWarn, "Timed out while sampling ADC");
			HAL_DMA_Abort(&hdma_tim8_ch4_trig_com);
			HAL_DMA_Abort(&hdma_tim8_up);
			HAL_TIM_Base_Stop(&htim8);
			continue;
		}
		HAL_TIM_Base_Stop(&htim8);
		LOG(Log_App, LevelDebug, "Got %lu samples in %lums", SAMPLING_LENGTH,
				stop - start);

		float fft = calc_fft(data1, data2, SAMPLING_LENGTH, window_data);
		LOG(Log_App, LevelInfo, "FFT result: %2.2f", fft);
		vTaskDelay(30);
	}
}
