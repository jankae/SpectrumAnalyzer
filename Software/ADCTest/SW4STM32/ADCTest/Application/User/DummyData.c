#include "DummyData.h"

#include "stm.h"
#include "log.h"
#include <math.h>

#define SAMPLING_FREQ		25000000

// TODO adjust
#define DATA_PORT			GPIOF
#define CLK_PORT			ADC_DUMMY_CLK_GPIO_Port
#define CLK_PIN				ADC_DUMMY_CLK_Pin

void generate_dummy_data(uint32_t frequency, uint16_t amplitude,
		uint32_t npoints, float phase) {
	uint32_t start = HAL_GetTick();
	LOG(Log_App, LevelInfo,
			"Generating dummy data (%lu points, %luHz, %u LSBp)...");
	for (uint32_t i = 0; i < npoints; i++) {
		if (i % 1000 == 0) {
			LOG(Log_App, LevelInfo, "%lu...", i);
		}
		float sin_arg = (float) i / SAMPLING_FREQ * frequency * 2 * M_PI + phase;
		while(sin_arg >= 200000 * 2 * M_PI) {
			sin_arg -= 200000 * 2 * M_PI;
		}
		int32_t signal = sin(sin_arg);
		if (signal >= 8192) {
			signal = 8191;
		} else if (signal < -8192) {
			signal = -8192;
		}
		DATA_PORT->ODR = 8192 + signal;
		CLK_PORT->BSRR = CLK_PIN;
		CLK_PORT->BSRR = CLK_PIN << 16;
	}
	uint32_t time = HAL_GetTick() - start;
//	uint64_t realtime_us = npoints * 1000000UL / 25000000;
	LOG(Log_App, LevelInfo, "... dummy data generated (%lu points, took %lums)",
			npoints, HAL_GetTick() - start);
}
