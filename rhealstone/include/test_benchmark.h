#ifndef TEST_BENCHMARK_H
#define TEST_BENCHMARK_H

/* Rhealstone benchmark */
#include "task_preemption.h"
#include "task_switch.h"
#include "interrupt_latency.h"
#include "semaphore_shuffle.h"
#include "deadlock_breaking_time.h"

void startRhealstoneBenchmark()
{
    /* Rhealstone benchmark */
    startTaskSwitchTest();
    // startTaskPreemptionTest();
    // startInterruptLatencyTest();
    // startSemaphoreShuffleTest();
    // startDeadlockBreakingTimeTest();
}

#endif // TEST_BENCHMARK_H
