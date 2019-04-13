#include "rf_settings.h"
#include "log.h"

#include "rffc5072.h"
#include "sampling.h"

void rf_tests() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");

//	 RFFC5072 test
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

	rffc5072_t r1, r2;
	r1.slice_address = 0x00;
	r1.CLK.gpio = GPIOE;
	r1.CLK.pin = GPIO_PIN_15;
	r1.ENX.gpio = GPIOE;
	r1.ENX.pin = GPIO_PIN_14;
	r1.DATA.gpio = GPIOE;
	r1.DATA.pin = GPIO_PIN_13;
	r1.RefCLKFreq = 25000000;
	r2 = r1;
	r2.slice_address = 0x01;
	rffc5072_init(&r1);
	rffc5072_init(&r2);
//	rffc5072_enabled(&r1, 1);
//	rffc5072_enabled(&r2, 1);
//	while(1) {
//		vTaskDelay(1000);
//	}

	uint32_t f_start = 150000000;
	uint32_t f_stop = 2500000000;
	uint32_t f_step = 10000000;
	for (uint32_t freq = f_start; freq <= f_stop; freq += f_step) {
		// set LO frequencies and wait for PLL lock
		vTaskDelay(1);
		rffc5072_enabled(&r1, 0);
		rffc5072_enabled(&r2, 0);
		vTaskDelay(1);
		rffc5072_set_LO(&r1, freq + 25000000);
		rffc5072_set_LO(&r2, freq - 18750000);
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
		const uint16_t avg = 30;
		for (uint16_t i = 0; i < avg; i++) {
			sum += sampling_get_dbm(10000);
		}
		LOG(Log_App, LevelInfo, "F: %lu, dbm: %2.2f", freq, sum / avg);
//		vTaskDelay(1000);
	};
	while(1) {
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
