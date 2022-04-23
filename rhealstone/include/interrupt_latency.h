#ifndef INTERRUPT_LATENCY_H
#define INTERRUPT_LATENCY_H

#include "stdint.h"

struct InterruptLatencyTestResults{
    uint32_t testTime;
    uint32_t testIteration;
};

void startInterruptLatencyTest();
struct InterruptLatencyTestResults* getInterruptLatencyTestResults();
void printInterruptLatencyTestResults();

#endif // INTERRUPT_LATENCY_H
