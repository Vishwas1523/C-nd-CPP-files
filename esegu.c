/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Soil Moisture Sensor → Percentage → UART (PuTTY)
 ******************************************************************************
 */
/* USER CODE END Header */

#include <stdio.h>
#include <string.h>

#include "adc.h"
#include "main.h"
#include "usart.h"

/* USER CALIBRATION VALUES ------------------------ */
#define DRY_ADC 3000  // ADC value when soil is DRY
#define WET_ADC 1000  // ADC value when soil is WET
/* ------------------------------------------------ */

uint32_t adcValue;
char msg[50];

/* Function Prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* Convert ADC → Moisture Percentage */
uint8_t Moisture_Percentage(uint32_t adc) {
  if (adc >= DRY_ADC) return 0;
  if (adc <= WET_ADC) return 100;

  float percent = 100.0f * (DRY_ADC - adc) / (DRY_ADC - WET_ADC);
  return (uint8_t)percent;
}

/* MAIN PROGRAM --------------------------------------------------------------*/
int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();         // FROM adc.c
  MX_USART2_UART_Init();  // FROM usart.c

  while (1) {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adcValue = HAL_ADC_GetValue(&hadc1);

    uint8_t moisture = Moisture_Percentage(adcValue);

    sprintf(msg, "Moisture: %d%%   (ADC: %lu)\r\n", moisture, adcValue);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    HAL_Delay(500);
  }
}

/* SYSTEM CLOCK CONFIG -------------------------------------------------------*/
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
}

/* GPIO INIT ---------------------------------------------------------------*/
static void MX_GPIO_Init(void) { __HAL_RCC_GPIOA_CLK_ENABLE(); }

void Error_Handler(void) {
  // blink LED on PB0 or PA5 depending on board
  while (1) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(200);
  }
}

/* END OF FILE --------------------------------------------------------------*/
