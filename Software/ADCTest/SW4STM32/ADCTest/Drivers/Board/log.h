#ifndef IOX_LOG_H_
#define IOX_LOG_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

#define LOG_USART			3
#define LOG_SENDBUF_LENGTH	2024
/*
 * If the log message does not fit into the remaining buffer space it is
 * discarded to not block program flow. For debugging purposes this behaviour
 * might be irritating. In this case uncomment the following line. Whenever the
 * buffer is too full, a call to log_write blocks until enough space is available.
 */
#define LOG_BLOCKING

#define USE_ASSERT
#define LOG_USE_MUTEXES

// log levels
#define LevelDebug 0x01
#define LevelInfo  0x02
#define LevelWarn  0x04
#define LevelError 0x08
#define LevelCrit  0x10
#define LevelAll   0x1F

// enabled levels for individual log sources
#define Log_Quectel 	(LevelAll)
#define Log_ATCMD		(LevelAll)
#define Log_System  	(LevelAll)
#define Log_Exti		(LevelAll)
#define Log_MAX11254	(LevelAll)
#define Log_MQTT 		(LevelAll)
#define Log_MQTTSN		(LevelAll)
#define Log_VL53L0X		(LevelAll)
#define Log_Example		(LevelAll)
#define Log_App		  	(LevelAll)
#define Log_TLS			(LevelAll)
#define Log_MAX30100	(LevelAll)
#define Log_MCP9808		(LevelAll)
#define Log_FFT			(LevelAll)

// if LevelDebug is omitted from this mask,
// debug message will not be logged regardless
// of individual source settings
#define Global_Level_Mask (LevelAll)

#define LOG(source, level, message, ...) do { \
    if (source & level & Global_Level_Mask) { \
       log_write(#source, level, message, ##__VA_ARGS__); \
    } \
} while (0)

#ifdef USE_ASSERT
#define ASSERT(x) do { \
	if(!(x)) { \
		log_write("    ASSERT", LevelCrit, "Assertion failed: %s, line %d", __FILE__, __LINE__); \
		log_flush(); \
		__BKPT(); \
	} \
} while (0)
#else
#define ASSERT(x)
#endif


void log_init();
void log_write(const char *module, uint8_t level, const char *fmt, ...);
void log_flush();

void log_force(const char *fmt, ...);

#endif
