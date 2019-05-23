/*
 * asynch.h
 *
 *  Created on: 24 Apr 2019
 *      Author: Jan
 */

#ifndef IOX_ASYNCH_H_
#define IOX_ASYNCH_H_

#define ASYNCH_STACK			512
#define ASYNCH_QUEUE_LENGTH		10

typedef void(*asynch_cb_t)(void *);

typedef enum {
	ASYNCH_RES_OK = 0,
	ASYNCH_RES_ERROR = 1,
} asynch_result_t;

asynch_result_t asynch_init();
asynch_result_t asynch_dispatch(asynch_cb_t cb, void *ptr);

#endif /* IOX_ASYNCH_H_ */
