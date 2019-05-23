#include "asynch.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "log.h"

typedef struct {
	asynch_cb_t cb;
	void *ptr;
} asynch_queue_item_t;

static StaticTask_t xTask;
static StackType_t xStack[ASYNCH_STACK];
static TaskHandle_t task_handle = NULL;
static StaticQueue_t xQueue;
static uint8_t queue_storage[ASYNCH_QUEUE_LENGTH * sizeof(asynch_queue_item_t)];
static QueueHandle_t queue_handle = NULL;

static void asynch_task(void *ptr) {
	LOG(Log_Asynch, LevelInfo, "Task start");
	while (1) {
		asynch_queue_item_t item;
		xQueueReceive(queue_handle, &item, portMAX_DELAY);
		if (item.cb) {
			LOG(Log_Asynch, LevelDebug, "Calling dispatched function: %p",
					item.cb);
			item.cb(item.ptr);
		}
	}
}

asynch_result_t asynch_init() {
	if (queue_handle == NULL) {
		LOG(Log_Asynch, LevelDebug, "Initializing dispatcher task/queue");
		queue_handle = xQueueCreateStatic(ASYNCH_QUEUE_LENGTH,
				sizeof(asynch_queue_item_t), queue_storage, &xQueue);
		task_handle = xTaskCreateStatic(asynch_task, "ASYNCH",
		ASYNCH_STACK, NULL, 5, xStack, &xTask);
	}
	return ASYNCH_RES_OK;
}

asynch_result_t asynch_dispatch(asynch_cb_t cb, void *ptr) {
	if (queue_handle == NULL) {
		LOG(Log_Asynch, LevelError,
				"Unable to add function %p, not initialized", cb);
		return ASYNCH_RES_ERROR;
	}
	asynch_queue_item_t item = { .cb = cb, .ptr = ptr };
	BaseType_t woken = pdFALSE;
	if (xQueueSendFromISR(queue_handle, &item, &woken) != pdPASS) {
		LOG(Log_Asynch, LevelError, "Unable to add function %p, queue full",
				cb);
		return ASYNCH_RES_ERROR;
	} else {
		LOG(Log_Asynch, LevelDebug, "Dispatched function %p", cb);
	}
	portYIELD_FROM_ISR(woken);
	return ASYNCH_RES_OK;
}
