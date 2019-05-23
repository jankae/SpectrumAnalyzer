#include "command.h"

#include "log.h"
#include "asynch.h"

#include <string.h>

static char linebuffer[64];

#define CMD_MAX_ARGC		10

static const command_entry_t *cmd_entries = NULL;
static uint16_t cmd_nentries = 0;

static void command_handler(void *unused);

static void log_callback(uint8_t *line, uint16_t length) {
	// disable log receive handler to avoid overwriting while evaluating command
	// TODO this could lead to issues if two commands are issued back-to-back. Consider implementing a command buffer
	log_set_receive_handler(NULL, NULL, 0);
	// remove trailing LF and terminate string
	line[length - 1] = 0;
	asynch_dispatch(command_handler, NULL);
}

static void command_handler(void *unused) {
	LOG(Log_Cmd, LevelDebug, "Parsing received line: %s", linebuffer);
	char *argv[CMD_MAX_ARGC];
	uint16_t argc;
	char *s = linebuffer;
	for (argc = 0; argc < CMD_MAX_ARGC; argc++) {
		argv[argc] = s;
		char *end = s + strcspn(s, " \t");
		if (!*end) {
			// found end of command string
			break;
		} else {
			*end = 0;
			end++;
			s = end + strspn(end, " \t");
			if (!*s) {
				// no next argument after last whitespace
				break;
			}
		}
	}
	argc++;

	// look for matching command
	for (uint16_t i = 0; i < cmd_nentries; i++) {
		if (strcasecmp(cmd_entries[i].name, argv[0]) == 0) {
			// found a match
			LOG(Log_Cmd, LevelDebug, "Found matching command: %s",
					cmd_entries[i].name);
			if (cmd_entries[i].cb) {
				cmd_entries[i].cb(argc, argv);
			}
			break;
		}
		if (i == cmd_nentries - 1) {
			LOG(Log_Cmd, LevelWarn, "Command \"%s\" not known", argv[0]);
		}
	}

	// enable log line callback again (has been disabled while parsing command)
	log_set_receive_handler(log_callback, (uint8_t*) linebuffer, sizeof(linebuffer));
}

command_result_t command_init(const command_entry_t *entries, uint16_t nentries) {
	asynch_init();
	log_set_receive_handler(log_callback, (uint8_t*) linebuffer, sizeof(linebuffer));
	cmd_entries = entries;
	cmd_nentries = nentries;
	return CMD_RES_OK;
}
