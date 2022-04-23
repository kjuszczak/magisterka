#ifndef TASK_SWITCH_H
#define TASK_SWITCH_H

#include "stdint.h"

#define TEST_ITERATION 1000000

struct TaskSwitchResults{
    uint32_t loopCmdTime;
    uint32_t testTime;
    uint32_t testIteration;
};

void startTaskSwitchTest();
struct TaskSwitchResults* getTestSwitchResults();
void printTestSwitchResults();

#endif // TASK_SWITCH_H
