/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "log.h"
#include "stm.h"
#include "DummyData.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

/* USER CODE BEGIN Variables */
#define DATALEN 30000
uint32_t data[DATALEN];
uint32_t data2[DATALEN];
extern SPI_HandleTypeDef hspi1;
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */
//static void SPI_Transmit(uint16_t *write, uint16_t *read, uint16_t length) {
//	for(uint16_t i=0;i<length;i++) {
//		uint16_t d = write[i];
//		uint16_t in = 0x0000;
//		for (uint16_t j = 0; j < 16; j++) {
//			if (d & 0x8000) {
//				HAL_GPIO_WritePin(SPI_MOSI_GPIO_Port, SPI_MOSI_Pin,
//						GPIO_PIN_SET);
//			} else {
//				HAL_GPIO_WritePin(SPI_MOSI_GPIO_Port, SPI_MOSI_Pin,
//						GPIO_PIN_RESET);
//			}
//			HAL_GPIO_WritePin(SPI_CLK_GPIO_Port, SPI_CLK_Pin,
//									GPIO_PIN_RESET);
//			in <<= 1;
//			d <<= 1;
//			if (HAL_GPIO_ReadPin(SPI_MISO_GPIO_Port, SPI_MISO_Pin)
//					== GPIO_PIN_SET) {
//				in |= 0x0001;
//			}
//			HAL_GPIO_WritePin(SPI_CLK_GPIO_Port, SPI_CLK_Pin,
//									GPIO_PIN_SET);
//		}
//		if(read) {
//			read[i] = in;
//		}
//	}
//	HAL_GPIO_WritePin(SPI_CLK_GPIO_Port, SPI_CLK_Pin,
//							GPIO_PIN_RESET);
//}
static void writeSPI(uint16_t address, uint16_t value) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[2] = {0x8000 | address, value};
//	HAL_SPI_Transmit(&hspi1, &send[0], 1, 10);
	HAL_SPI_Transmit(&hspi1, send, 2, 10);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
}
static uint16_t readSPI(uint16_t address) {
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint16_t send[2] = {address & 0x7FFF, 0};
	uint16_t rec[2];
//	SPI_Transmit(send, rec, 2);
	HAL_SPI_TransmitReceive(&hspi1, send, rec, 2, 10);
//	HAL_SPI_TransmitReceive(&hspi1, &send[1], &rec[1], 1, 10);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	return rec[1];
}
/* USER CODE END FunctionPrototypes */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 1024);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
	log_init();
	LOG(Log_System, LevelInfo, "Start");

	log_flush();
	while(1) {
		fft_spi_mem_test();
		vTaskDelay(1000);
	}
	generate_dummy_data(10000000, 4000, 250000, 0);
	while(1) {
		vTaskDelay(1000);
	}

//	LOG(Log_System, LevelInfo, "Readback: 0x%04x", readSPI(0x5555));
//	while(1);

#define NUM_WORDS	1024
	for (uint16_t i = 0; i < NUM_WORDS; i++) {
		writeSPI(i, i);
	}
	LOG(Log_System, LevelInfo, "%d words written.", NUM_WORDS);

	uint8_t error = 0;
	for (uint16_t i = 0; i < NUM_WORDS; i++) {
		uint16_t val = readSPI(i);
		if (val != i) {
			LOG(Log_System, LevelInfo,
					"Error: expected %d, got %d at position %d", i, val, i);
			error = 1;
			break;
		}
	}
	if (!error) {
		LOG(Log_System, LevelInfo, "%d words verified correctly", NUM_WORDS);
	}

	while (1) {
		vTaskDelay(1000);
	}

	extern TIM_HandleTypeDef htim8;
	extern DMA_HandleTypeDef hdma_tim8_up, hdma_tim8_ch4_trig_com;
	while (1) {
		HAL_Delay(5);
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		HAL_DMA_Start(&hdma_tim8_up, &(GPIOE->IDR), data2,
		DATALEN);
		HAL_DMA_Start(&hdma_tim8_ch4_trig_com, &(GPIOE->IDR), data,
		DATALEN);
		/* Enable the TIM Update DMA request */
		__HAL_TIM_ENABLE_DMA(&htim8, TIM_DMA_UPDATE | TIM_DMA_CC4);
		HAL_TIM_Base_Start(&htim8);
//		while(1);
		HAL_StatusTypeDef res = HAL_DMA_PollForTransfer(&hdma_tim8_up, HAL_DMA_FULL_TRANSFER,
				1000);
		res = HAL_DMA_PollForTransfer(&hdma_tim8_ch4_trig_com, HAL_DMA_FULL_TRANSFER,
				100);
//		LOG(Log_System, LevelDebug, "Result: 0x%04x", res);
		if (res == HAL_OK) {
			uint16_t last = data[1];
			uint8_t error = 0;
			for (uint16_t i = 1; i < DATALEN; i++) {
				if (!((last ^ data2[i]) & 0x01)) {
					error = 1;
					LOG(Log_System, LevelWarn, "Error at data2, sample %d", i);
					break;
				}
				last = data2[i];
				if (i < DATALEN - 1) {
					if (!((last ^ data[i + 1]) & 0x01)) {
						error = 1;
						LOG(Log_System, LevelWarn, "Error at data2, sample %d",
								i + 1);
						break;
					}
					last = data[i + 1];
				}
			}
			if (!error) {
				LOG(Log_System, LevelInfo, "Sample OK");
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			} else {
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
			}
		} else {
			HAL_DMA_Abort(&hdma_tim8_up);
			HAL_DMA_Abort(&hdma_tim8_ch4_trig_com);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		}
		HAL_TIM_Base_Stop(&htim8);
	}
	/* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
