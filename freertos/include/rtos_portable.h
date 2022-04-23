#ifndef RTOS_PORTABLE_H
#define RTOS_PORTABLE_H

#include "stdint.h"

typedef uint32_t Ticks;
typedef void (* TaskFunction) (void*);

void createTask(TaskFunction task, const char *pcName, uint32_t priority);
void switchTask();
void suspendTask();
void resumeTaskFromIsr();
uint8_t createSemaphore();
uint8_t takeSemaphore();
uint8_t giveSemaphore();

void delayTask(uint32_t delay);
void deleteTask();

#endif // RTOS_PORTABLE_H