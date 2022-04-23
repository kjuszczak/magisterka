#ifndef TASK_PREEMPTION_H
#define TASK_PREEMPTION_H

#include "stdint.h"

struct TaskPreemptionResults{
    uint32_t testTime;
    uint32_t testIteration;
};

void startTaskPreemptionTest();
struct TaskPreemptionResults* getTestPreemptionResults();
void printTestPreemptionResults();

#endif // TASK_PREEMPTION_H
