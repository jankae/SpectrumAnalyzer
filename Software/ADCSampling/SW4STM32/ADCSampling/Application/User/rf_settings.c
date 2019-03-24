#include "rf_settings.h"
#include "log.h"

#include "rffc5072.h"

void rf_tests() {
	log_init();
	LOG(Log_App, LevelInfo, "Start");

	rffc5072_t r;
	r.RefCLKFreq = 10000000;
	r.slice_address = 0x00;
	r.CLK.gpio = GPIOE;
	r.CLK.pin = GPIO_PIN_15;
	r.ENX.gpio = GPIOE;
	r.ENX.pin = GPIO_PIN_14;
	r.DATA.gpio = GPIOE;
	r.DATA.pin = GPIO_PIN_13;
//	r.RefCLKFreq = 26000000;
	rffc5072_init(&r);

//	while(rffc5072_locked(&r) != RFFC5072_RES_OK) {
//		vTaskDelay(1000);
//	}
	rffc5072_enabled(&r, 1);
}
