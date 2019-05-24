#include <rf_tests.h>
#include "log.h"

#include "rffc5072.h"
#include "command.h"
#include "FFTSampling.h"
#include <stdlib.h>

#define FFT_POINTS 				25000

static rffc5072_t *lo_control;

void cmd_lo(uint16_t argc, char *argv[]) {
	if (argc != 2) {
		LOG(Log_App, LevelInfo, "Usage: lo <freq>");
		return;
	}
	uint32_t freq = strtoul(argv[1], NULL, 10);
	LOG(Log_App, LevelInfo, "Setting LO to %luHz", freq);
	rffc5072_set_LO(lo_control, freq);
	vTaskDelay(1);
	rffc5072_enabled(lo_control, 1);
	vTaskDelay(1);
	LOG(Log_App, LevelInfo, "Waiting for LO to lock...");
	for (uint8_t i = 0; i < 10; i++) {
		if (rffc5072_locked(lo_control) == RFFC5072_RES_OK) {
			LOG(Log_App, LevelInfo, "LO locked");
			return;
		} else {
			vTaskDelay(1);
			rffc5072_enabled(lo_control, 0);
			vTaskDelay(1);
			rffc5072_enabled(lo_control, 1);
			vTaskDelay(1);
		}
	}
	LOG(Log_App, LevelWarn, "... timed out, LO unlocked");
}

void lo_setting() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");
	// RFFC5072 test
	// initialize reset pin
	GPIO_InitTypeDef g;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pin = GPIO_PIN_2;
	g.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOB, &g);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	vTaskDelay(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	vTaskDelay(10);

	rffc5072_t r1, r2, r3, r4;
	r1.slice_address = 0x01;
	r1.CLK.gpio = GPIOF;
	r1.CLK.pin = GPIO_PIN_4;
	r1.ENX.gpio = GPIOB;
	r1.ENX.pin = GPIO_PIN_6;
	r1.DATA.gpio = GPIOC;
	r1.DATA.pin = GPIO_PIN_2;
	r1.RefCLKFreq = 25000000;
	rffc5072_init(&r1);

	lo_control = &r1;

	uint32_t f_start = 85000000;
	uint32_t f_stop = 2500000000;
	uint32_t f_step = 2000000;
	while (1) {
		uint32_t start = HAL_GetTick();
		for (uint32_t freq = f_start; freq <= f_stop; freq += f_step) {
			// set LO frequencies and wait for PLL lock
			rffc5072_enabled(&r1, 0);
			rffc5072_set_LO(&r1, freq - 25000000);
//			vTaskDelay(1);
			rffc5072_enabled(&r1, 1);
//			vTaskDelay(1);
//			while (rffc5072_locked(&r1) != RFFC5072_RES_OK) {
//				vTaskDelay(1);
//				rffc5072_enabled(&r1, 0);
//				vTaskDelay(1);
//				rffc5072_enabled(&r1, 1);
//				vTaskDelay(1);
//			}
			LOG(Log_App, LevelInfo, "F: %lu", freq);
			vTaskDelay(5);
		}
		LOG(Log_App, LevelInfo, "Sweep took %lums", HAL_GetTick() - start);
	}

	command_entry_t cmds[] = { { cmd_lo, "lo" }, };
	command_init(cmds, 1);
	while (1) {
		vTaskDelay(1000);
	}

}

void rf_mixer_wobble() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");

//	 RFFC5072 test
	// initialize reset pin
	GPIO_InitTypeDef g;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pin = GPIO_PIN_2;
	g.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOB, &g);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	vTaskDelay(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	vTaskDelay(10);

	rffc5072_t r1, r2, r3, r4;
	r1.slice_address = 0x00;
	r1.CLK.gpio = GPIOF;
	r1.CLK.pin = GPIO_PIN_4;
	r1.ENX.gpio = GPIOB;
	r1.ENX.pin = GPIO_PIN_6;
	r1.DATA.gpio = GPIOC;
	r1.DATA.pin = GPIO_PIN_2;
	r1.RefCLKFreq = 25000000;
	r2 = r1;
	r2.slice_address = 0x01;
	r3 = r1;
	r3.slice_address = 0x02;
	r4 = r1;
	r4.slice_address = 0x03;
	rffc5072_init(&r1);
	rffc5072_init(&r2);
	rffc5072_init(&r3);
	rffc5072_init(&r4);
	while (1) {
		vTaskDelay(1000);
	}
//	rffc5072_enabled(&r1, 1);
//	rffc5072_enabled(&r2, 1);
//	while(1) {
//		vTaskDelay(1000);
//	}

	uint32_t f_start = 1500000000;
	uint32_t f_stop = 2500000000;
	uint32_t f_step = 2000000;
	while (1) {
		for (uint32_t freq = f_start; freq <= f_stop; freq += f_step) {
			// set LO frequencies and wait for PLL lock
//		vTaskDelay(1);
			rffc5072_enabled(&r1, 0);
			rffc5072_enabled(&r2, 0);
//		vTaskDelay(1);
			rffc5072_set_LO(&r1, freq - 25000000);
			rffc5072_set_LO(&r2, freq + 18750000);
			vTaskDelay(1);
			rffc5072_enabled(&r1, 1);
			rffc5072_enabled(&r2, 1);
			vTaskDelay(1);
			while (rffc5072_locked(&r1) != RFFC5072_RES_OK) {
				vTaskDelay(1);
				rffc5072_enabled(&r1, 0);
				vTaskDelay(1);
				rffc5072_enabled(&r1, 1);
				vTaskDelay(1);
			}
			while (rffc5072_locked(&r2) != RFFC5072_RES_OK) {
				vTaskDelay(1);
				rffc5072_enabled(&r2, 0);
				vTaskDelay(1);
				rffc5072_enabled(&r2, 1);
				vTaskDelay(1);
			}

			// measure final IF
			float sum = 0.0f;
			const uint16_t avg = 10;
			for (uint16_t i = 0; i < avg; i++) {
				sum += sampling_get_dbm(30000);
			}
			LOG(Log_App, LevelInfo, "F: %lu, dbm: %2.2f", freq, sum / avg);
//		vTaskDelay(1000);
		}
	}
	while (1) {
		vTaskDelay(1000);
//		float sum = 0.0f;
//		const uint16_t avg = 50;
//		for(uint16_t i=0;i<avg;i++) {
//			sum += sampling_get_dbm(10000);
//		}
//		LOG(Log_App, LevelInfo, "FFT result: %2.2f", sum / avg);
	}
//
////	while(rffc5072_locked(&r) != RFFC5072_RES_OK) {
////		vTaskDelay(1000);
////	}
//	rffc5072_enabled(&r, 1);
	// ADC FFT test
//	sampling_start();
}

void rf_fft_fpga_test() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");
	while(1) {
		float dbm = FFT_take_sample(FFT_POINTS, FFT_WINDOW_FLATTOP);
		LOG(Log_App, LevelInfo, "dbm: %f", dbm);
		vTaskDelay(1000);
	}
}

void rf_spectrum_analyzer() {
	log_init();
	LOG(Log_App, LevelInfo, "Spectrum analyzer start");
	//	 RFFC5072 test
	// initialize reset pin
	GPIO_InitTypeDef g;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pin = GPIO_PIN_2;
	g.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOB, &g);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	vTaskDelay(10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	vTaskDelay(10);

	rffc5072_t r1, r2, r3;
	r1.slice_address = 0x01;
	r1.CLK.gpio = GPIOF;
	r1.CLK.pin = GPIO_PIN_4;
	r1.ENX.gpio = GPIOB;
	r1.ENX.pin = GPIO_PIN_6;
	r1.DATA.gpio = GPIOC;
	r1.DATA.pin = GPIO_PIN_2;
	r1.RefCLKFreq = 25000000;
	r2 = r1;
	r2.slice_address = 0x03;
	r3 = r1;
	r3.slice_address = 0x02;
	rffc5072_result_t res = rffc5072_init(&r1);
	res |= rffc5072_init(&r2);
	res |= rffc5072_init(&r3);

	if (res == RFFC5072_RES_OK) {
		LOG(Log_App, LevelInfo, "Mixers initialized");
	} else {
		LOG(Log_App, LevelError, "Error initializing mixers");
		while (1)
			;
	}

	/*
	 * Frequency planning:
	 * 1. LO: 2.15GHz
	 * 2. LO: 403MHz
	 * 3. LO: 18.75MHz
	 *
	 * 1. Mixer: 2.15-3.95GHz
	 * 2. Mixer: 1747MHz
	 * 3. Mixer: 384.25MHz
	 */
	rffc5072_set_LO(&r2, 1747000000);
	rffc5072_enabled(&r2, 1);
	rffc5072_set_LO(&r3, 384250000);
	rffc5072_enabled(&r3, 1);

	uint32_t f_start = 19000000;
	uint32_t f_stop = 21000000;
	uint16_t steps = 501;
	uint32_t f_step = (f_stop - f_start) / (steps - 1);

	uint32_t fft_points = 25000000UL * 3.7f / f_step;

	while(1) {
		for (uint32_t f = f_start; f <= f_stop; f += f_step) {
			// set first mixer
			rffc5072_enabled(&r1, 0);
			rffc5072_set_LO(&r1, 2150000000 + f);
			rffc5072_enabled(&r1, 1);
			vTaskDelay(2);
			float dbm = FFT_take_sample(fft_points, FFT_WINDOW_FLATTOP);
			LOG(Log_App, LevelInfo, "freq: %lu, dbm: %f", f, dbm);
		}
	}
}
