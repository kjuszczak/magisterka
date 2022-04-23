#include "rtos_portable.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* TASK 1 */
#define TASK_1_INDEX 1

TaskHandle_t xHandleTask_1;

/* TASK 2 */
#define TASK_2_INDEX 2

TaskHandle_t xHandleTask_2;

SemaphoreHandle_t xSemaphore = NULL;

static uint8_t taskIndex = 1;

void createTask(TaskFunction task, const char *pcName, uint32_t priority)
{
    switch (taskIndex)
    {
        case TASK_1_INDEX:
            xTaskCreate(task,						
                pcName, 						
                configMINIMAL_STACK_SIZE, 			
                NULL, 								
                priority, 								
                &xHandleTask_1);
            break;
        case TASK_2_INDEX:
            xTaskCreate(task,						
                pcName, 						
                configMINIMAL_STACK_SIZE, 			
                NULL, 								
                priority, 								
                &xHandleTask_2);
            break;
        default:
            return;
    }

    taskIndex++;							
}

void switchTask()
{
    taskYIELD();
}

void suspendTask()
{
    vTaskSuspend(NULL);
}

void delayTask(uint32_t delay)
{
    vTaskDelay(delay);
}

void deleteTeask()
{
    vTaskDelete(NULL);
}

void resumeTaskFromIsr()
{
    BaseType_t xYieldRequired;

    xYieldRequired = xTaskResumeFromISR(xHandleTask_1);
    portYIELD_FROM_ISR( xYieldRequired );
}

uint8_t createSemaphore()
{
    xSemaphore = xSemaphoreCreateMutex();
    return xSemaphore != NULL;
}

uint8_t takeSemaphore()
{
    return xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE;
}

uint8_t giveSemaphore()
{
    return xSemaphoreGive(xSemaphore) == pdTRUE;
}
