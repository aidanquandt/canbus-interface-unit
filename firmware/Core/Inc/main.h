/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "common_defs.h"
#include "interruptHandler.h"
#include "canBus.h"
#include "adc.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */



/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ch7_Speed_Pin GPIO_PIN_3
#define ch7_Speed_GPIO_Port GPIOA
#define ch7_Speed_EXTI_IRQn EXTI3_IRQn
#define ch6_Speed_Pin GPIO_PIN_4
#define ch6_Speed_GPIO_Port GPIOA
#define ch6_Speed_EXTI_IRQn EXTI4_IRQn
#define ch5_Analog_Pin GPIO_PIN_5
#define ch5_Analog_GPIO_Port GPIOA
#define ch4_Analog_Pin GPIO_PIN_6
#define ch4_Analog_GPIO_Port GPIOA
#define ch3_Analog_Pin GPIO_PIN_7
#define ch3_Analog_GPIO_Port GPIOA
#define ch2_Analog_Pin GPIO_PIN_4
#define ch2_Analog_GPIO_Port GPIOC
#define ch1_Analog_Pin GPIO_PIN_5
#define ch1_Analog_GPIO_Port GPIOC
#define ch0_Analog_Pin GPIO_PIN_0
#define ch0_Analog_GPIO_Port GPIOB
#define STATUS_LED_Pin GPIO_PIN_2
#define STATUS_LED_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

#define CH7_SPEED_PIN ch7_Speed_Pin
#define CH7_SPEED_GPIO_PORT ch7_Speed_GPIO_Port
#define CH7_SPEED_EXTI_IRQn ch7_Speed_EXTI_IRQn
#define CH6_SPEED_PIN ch6_Speed_Pin
#define CH6_SPEED_GPIO_PORT ch6_Speed_GPIO_Port
#define CH6_SPEED_EXTI_IRQn ch6_Speed_EXTI_IRQn
#define CH5_ANALOG_PIN ch5_Analog_Pin
#define CH5_ANALOG_GPIO_PORT ch5_Analog_GPIO_Port
#define CH4_ANALOG_PIN ch4_Analog_Pin
#define CH4_ANALOG_GPIO_PORT ch4_Analog_GPIO_Port
#define CH3_ANALOG_PIN ch3_Analog_Pin
#define CH3_ANALOG_GPIO_PORT ch3_Analog_GPIO_Port
#define CH2_ANALOG_PIN ch2_Analog_Pin
#define CH2_ANALOG_GPIO_PORT ch2_Analog_GPIO_Port
#define CH1_ANALOG_PIN ch1_Analog_Pin
#define CH1_ANALOG_GPIO_PORT ch1_Analog_GPIO_Port
#define CH0_ANALOG_PIN ch0_Analog_Pin
#define CH0_ANALOG_GPIO_PORT ch0_Analog_GPIO_Port
#define STATUS_LED_PIN STATUS_LED_Pin
#define STATUS_LED_GPIO_PORT STATUS_LED_GPIO_Port

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
