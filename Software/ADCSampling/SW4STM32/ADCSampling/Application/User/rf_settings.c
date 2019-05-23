#include "rf_settings.h"
#include "log.h"

#include "rffc5072.h"
#include "sampling.h"
#include "command.h"
#include <stdlib.h>

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
	g.Pin = GPIO_PIN_12;
	g.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOE, &g);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	vTaskDelay(10);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	vTaskDelay(10);

	rffc5072_t r1;
	r1.slice_address = 0x00;
	r1.CLK.gpio = GPIOE;
	r1.CLK.pin = GPIO_PIN_15;
	r1.ENX.gpio = GPIOE;
	r1.ENX.pin = GPIO_PIN_14;
	r1.DATA.gpio = GPIOE;
	r1.DATA.pin = GPIO_PIN_13;
	r1.RefCLKFreq = 25000000;
	rffc5072_init(&r1);

	lo_control = &r1;

	uint32_t f_start = 150000000;
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

void rf_tests() {
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
