#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "board_config.h"

/**
* @brief    Task for blinking an LED every second
* 
* @param    pvParameters void pointer to task parameters
* 
* @retval   void
*/
void LedBlinky_Task(void *pvParameters) {
    while (1) {
        if (uart_transmit("Hello world from FreeRTOS!\r\n"))
            toggle_led();
        delay(1000);
    }
}

int main ( void )
{
    board_config();

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
