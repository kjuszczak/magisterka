#ifndef INTERTASK_MSG_LATENCY_H
#define INTERTASK_MSG_LATENCY_H

#include "stdint.h"

struct IntertaskMsgLatencyTestResults{
    uint32_t testTime;
    uint32_t testIteration;
};

void startIntertaskMsgLatencyTest();
struct IntertaskMsgLatencyTestResults* getIntertaskMsgLatencyTestResults();
void printIntertaskMsgLatencyTestResults();

#endif // INTERTASK_MSG_LATENCY_H
