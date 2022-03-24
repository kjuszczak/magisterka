#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "board_config.h"
#include "stm32f2xx_hal.h"

static GPIO_InitTypeDef  GPIO_InitStruct;

#if !defined  (Error_Handler)
extern void Default_Handler(void);
#define Error_Handler    Default_Handler
#endif /* Error_Handler */

/** @brief   LED pin */
#define LED1_PIN GPIO_PIN_7
/** @brief   LED port */
#define LED1_PORT GPIOB

/**
* @brief    Task for blinking an LED every second
* 
* @param    pvParameters void pointer to task parameters
* 
* @retval   void
*/
void LedBlinky_Task(void *pvParameters) {
    while (1) {
        HAL_GPIO_TogglePin(LED1_PORT, LED1_PIN);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

int main ( void )
{
    board_config();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin   = LED1_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LED1_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_SET);

    xTaskCreate( LedBlinky_Task,						/* The function that implements the task. */
                 "LedBlinky", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
                 configMINIMAL_STACK_SIZE, 				/* The size of the stack to allocate to the task. */
                 NULL, 									/* The parameter passed to the task - just to check the functionality. */
                 3, 										/* The priority assigned to the task. */
                 NULL );									/* The task handle is not required, so NULL is passed. */
    vTaskStartScheduler();

    /* should never reach */
    while (1){
    }
    return 0;
}
