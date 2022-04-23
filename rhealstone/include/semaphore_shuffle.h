#ifndef SEMAPHORE_SHUFFLE_H
#define SEMAPHORE_SHUFFLE_H

#include "stdint.h"

struct SemaphoreShuffleTestResults{
    uint32_t testTime;
    uint32_t testIteration;
};

void startSemaphoreShuffleTest();
struct SemaphoreShuffleTestResults* getSemaphoreShuffleTestResults();
void printSemaphoreShuffleTestResults();

#endif // SEMAPHORE_SHUFFLE_H
