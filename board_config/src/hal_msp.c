/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f2xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;

#define STLK_RX_Pin GPIO_PIN_8
#define STLK_TX_Pin GPIO_PIN_9

#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TXD0_Pin GPIO_PIN_13

/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* USART3 DMA Init */
    /* USART3_RX Init */
    hdma_usart3_rx.Instance = DMA1_Stream1;
    hdma_usart3_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart3_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart3_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart3_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart3_rx.Init.Mode = DMA_NORMAL;
    hdma_usart3_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart3_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_usart3_rx);

    __HAL_LINKDMA(huart,hdmarx,hdma_usart3_rx);

    /* USART3_TX Init */
    hdma_usart3_tx.Instance = DMA1_Stream3;
    hdma_usart3_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart3_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart3_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart3_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart3_tx.Init.Mode = DMA_NORMAL;
    hdma_usart3_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart3_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_usart3_tx);

    __HAL_LINKDMA(huart,hdmatx,hdma_usart3_tx);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }

}

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin|STLK_TX_Pin);

    /* USART3 DMA DeInit */
    HAL_DMA_DeInit(huart->hdmarx);
    HAL_DMA_DeInit(huart->hdmatx);

    /* USART3 interrupt DeInit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }

}

// void HAL_ETH_MspInit(ETH_HandleTypeDef* heth)
// {
//   GPIO_InitTypeDef GPIO_InitStruct = {0};
//   if(heth->Instance==ETH)
//   {
//     /* Peripheral clock enable */
//     __HAL_RCC_ETH_CLK_ENABLE();

//     __HAL_RCC_GPIOC_CLK_ENABLE();
//     __HAL_RCC_GPIOA_CLK_ENABLE();
//     __HAL_RCC_GPIOB_CLK_ENABLE();
//     __HAL_RCC_GPIOG_CLK_ENABLE();
//     /**ETH GPIO Configuration
//     PC1     ------> ETH_MDC
//     PA1     ------> ETH_REF_CLK
//     PA2     ------> ETH_MDIO
//     PA7     ------> ETH_CRS_DV
//     PC4     ------> ETH_RXD0
//     PC5     ------> ETH_RXD1
//     PB13     ------> ETH_TXD1
//     PG11     ------> ETH_TX_EN
//     PG13     ------> ETH_TXD0
//     */
//     GPIO_InitStruct.Pin = RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//     GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
//     HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//     GPIO_InitStruct.Pin = RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//     GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
//     HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//     GPIO_InitStruct.Pin = RMII_TXD1_Pin;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//     GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
//     HAL_GPIO_Init(RMII_TXD1_GPIO_Port, &GPIO_InitStruct);

//     GPIO_InitStruct.Pin = RMII_TX_EN_Pin|RMII_TXD0_Pin;
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//     GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
//     HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

//     /* ETH interrupt Init */
//     HAL_NVIC_SetPriority(ETH_IRQn, 4, 0);
//     HAL_NVIC_EnableIRQ(ETH_IRQn);
//   }
// }

// void HAL_ETH_MspDeInit(ETH_HandleTypeDef* heth)
// {
//   if(heth->Instance==ETH)
//   {
//     /* Peripheral clock disable */
//     __HAL_RCC_ETH_CLK_DISABLE();

//     /**ETH GPIO Configuration
//     PC1     ------> ETH_MDC
//     PA1     ------> ETH_REF_CLK
//     PA2     ------> ETH_MDIO
//     PA7     ------> ETH_CRS_DV
//     PC4     ------> ETH_RXD0
//     PC5     ------> ETH_RXD1
//     PB13     ------> ETH_TXD1
//     PG11     ------> ETH_TX_EN
//     PG13     ------> ETH_TXD0
//     */
//     HAL_GPIO_DeInit(GPIOC, RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin);

//     HAL_GPIO_DeInit(GPIOA, RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin);

//     HAL_GPIO_DeInit(RMII_TXD1_GPIO_Port, RMII_TXD1_Pin);

//     HAL_GPIO_DeInit(GPIOG, RMII_TX_EN_Pin|RMII_TXD0_Pin);

//     /* ETH interrupt DeInit */
//     HAL_NVIC_DisableIRQ(ETH_IRQn);
//   }

// }

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base)
{
  if(htim_base->Instance==TIM2)
  {
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
  else if(htim_base->Instance==TIM5)
  {
    __HAL_RCC_TIM5_CLK_ENABLE();
  }
}