#include "rtos_portable.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#define TASK_BASE_PRIORITY 3u

TaskHandle_t xHandleTask[MAX_NUMBER_OF_TASKS];

SemaphoreHandle_t xSemaphore = NULL;
QueueHandle_t xStructQueue = NULL;

void createTask(TaskFunction task, const char *pcName, uint32_t priority, uint8_t taskIndex)
{
    xTaskCreate(task,						
        pcName, 						
        configMINIMAL_STACK_SIZE, 			
        NULL, 								
        TASK_BASE_PRIORITY + priority, 								
        &xHandleTask[taskIndex]);	
}

void switchTask()
{
    taskYIELD();
}

void suspendTask(uint8_t taskIndex)
{
    vTaskSuspend(xHandleTask[taskIndex]);
}

void resumeTask(uint8_t taskIndex)
{
    vTaskResume(xHandleTask[taskIndex]);
}

void resumeTaskFromIsr(uint8_t taskIndex)
{
    BaseType_t xYieldRequired;

    xYieldRequired = xTaskResumeFromISR(xHandleTask[taskIndex]);
    portYIELD_FROM_ISR(xYieldRequired);
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

uint8_t createQueue(uint8_t queueSize)
{
    xStructQueue = xQueueCreate(queueSize, sizeof(uint8_t));
    return xStructQueue != NULL;
}

uint8_t sendMsg(void* msg)
{
    return xQueueSend(xStructQueue, msg, portMAX_DELAY) == pdPASS;
}

uint8_t receiveMsg(void* msg)
{
    return xQueueReceive(xStructQueue, msg, portMAX_DELAY) == pdPASS;
}