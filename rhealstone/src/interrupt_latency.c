#include "interrupt_latency.h"

/* Board management API */
#include "board_config.h"

/* RTOS API */
#include "rtos_portable.h"

#define TEST_ITERATION    10000

/* TASK 1 PARAMS */
#define TASK_1_PRIORITY   0

/* TASK 2 PARAMS */
#define TASK_2_PRIORITY   0

static struct InterruptLatencyTestResults testResults = {
    .testTime = 0,
    .testIteration = TEST_ITERATION
};

static uint32_t testIndex = 0;

static void initTest();
static void isrCallback();
static void taskInterruptLatencyTest_1(void *pvParameters);
static void taskInterruptLatencyTest_2(void *pvParameters);

void startInterruptLatencyTest()
{
    initTest();
    createTask(taskInterruptLatencyTest_1, "InterruptLatencyTestTask_1", TASK_1_PRIORITY, TASK_1_INDEX);
    createTask(taskInterruptLatencyTest_2, "InterruptLatencyTestTask_2", TASK_2_PRIORITY, TASK_2_INDEX);
}

void printInterruptLatencyTestResults()
{
    print("Interrupt latency test: testTime:%u\n", testResults.testTime);
}

struct InterruptLatencyTestResults* getInterruptLatencyTestResults()
{
    return &testResults;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")
static void initTest()
{
    setIsrCallback(isrCallback);
}

static void isrCallback()
{
    testResults.testTime += getTimerValue();

    static uint8_t isFirstTime = 1;
    if (isFirstTime)
    {
        testResults.testTime = 0;
        isFirstTime = 0;
        return;
    }

    if (testIndex >= TEST_ITERATION)
    {
        stopIsr();
        printInterruptLatencyTestResults();
        return;
    }
    testIndex++;
    startTimer();
}

static void taskInterruptLatencyTest_1(void *pvParameters)
{
    startIsr();
    for (;;) 
    {
        delay(10); // delay 10 ms
    }
}

static void taskInterruptLatencyTest_2(void *pvParameters)
{
    for (;;)
    {
        delay(10); // delay 10 ms
    }
}
#pragma GCC pop_options