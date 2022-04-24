#ifndef DEADLOCK_BREAKING_TIME_H
#define DEADLOCK_BREAKING_TIME_H

#include "stdint.h"

struct DeadlockBreakingTimeTestResults{
    uint32_t testTime;
    uint32_t testIteration;
};

void startDeadlockBreakingTimeTest();
struct DeadlockBreakingTimeTestResults* getDeadlockBreakingTimeTestResults();
void printDeadlockBreakingTimeTestResults();

#endif // DEADLOCK_BREAKING_TIME_H
