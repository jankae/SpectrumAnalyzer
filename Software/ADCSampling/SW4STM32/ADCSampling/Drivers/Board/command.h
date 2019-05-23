/*
 * command.h
 *
 *  Created on: 24 Apr 2019
 *      Author: Jan
 */

#ifndef IOX_COMMAND_H_
#define IOX_COMMAND_H_

#include <stdint.h>

typedef void (*command_callback_t)(uint16_t argc, char *argv[]);

typedef struct {
	command_callback_t cb;
	const char *name;
} command_entry_t;

typedef enum {
	CMD_RES_OK = 0,
	CMD_RES_ERROR,
} command_result_t;

command_result_t command_init(const command_entry_t *entries, uint16_t nentries);

#endif /* IOX_COMMAND_H_ */
