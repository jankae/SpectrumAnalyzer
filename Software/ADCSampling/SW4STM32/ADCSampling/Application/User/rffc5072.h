/*
 * rffc5072.h
 *
 *  Created on: Mar 24, 2019
 *      Author: jan
 */

#ifndef APPLICATION_USER_RFFC5072_H_
#define APPLICATION_USER_RFFC5072_H_

#include "stm.h"

typedef struct {
	GPIO_TypeDef *gpio;
	uint16_t pin;
} rffc5072_pin_t;

typedef struct {
	rffc5072_pin_t ENX, CLK, DATA;
	uint32_t RefCLKFreq;
	uint8_t slice_address;
} rffc5072_t;

typedef enum {
	RFFC5072_RES_OK,
	RFFC5072_RES_ERROR,
} rffc5072_result_t;

rffc5072_result_t rffc5072_init(rffc5072_t *r);
rffc5072_result_t rffc5072_set_LO(rffc5072_t *r, uint32_t freq);
rffc5072_result_t rffc5072_enabled(rffc5072_t *r, uint8_t enabled);
rffc5072_result_t rffc5072_locked(rffc5072_t *r);

#endif /* APPLICATION_USER_RFFC5072_H_ */
