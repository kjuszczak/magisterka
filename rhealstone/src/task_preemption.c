#include "task_preemption.h"

/* Board management API */
#include "board_config.h"

/* RTOS API */
#include "rtos_portable.h"

#define TEST_ITERATION    1000

/* TASK 1 PARAMS */
#define TASK_1_PRIORITY   1

/* TASK 2 PARAMS */
#define TASK_2_PRIORITY   0

static struct TaskPreemptionResults testResults = {
    .testTime = 0,
    .testIteration = TEST_ITERATION
};

static uint8_t checkFlag = 0;

static void initTest();
static void isrCallback();
static void taskPreemptionTest_1(void *pvParameters);
static void taskPreemptionTest_2(void *pvParameters);

void startTaskPreemptionTest()
{
    createTask(taskPreemptionTest_1, "TaskPreemptionTest_1", TASK_1_PRIORITY, TASK_1_INDEX);
}

void printTestPreemptionResults()
{
    print("Task preemption test: testTime:%u\n", testResults.testTime);
}

struct TaskPreemptionResults* getTestPreemptionResults()
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
    static uint8_t isFirstTime = 1;
    if (isFirstTime)
    {
        isFirstTime = 0;
        return;
    }

    stopIsr();

    startTimer();
    resumeTaskFromIsr(TASK_1_INDEX);
}

static void taskPreemptionTest_1(void *pvParameters)
{
    initTest();

    createTask(taskPreemptionTest_2, "TaskPreemptionTest_2", TASK_2_PRIORITY, TASK_2_INDEX);

    for (int i = 0; i < TEST_ITERATION; i++)
    {
        startIsr();
        checkFlag = 0;

        suspendTask(TASK_1_INDEX);
        testResults.testTime += getTimerValue();
        stopTimer();

        if (!checkFlag)
        {
            print("Error\n");
            return;
        }
    }

    printTestPreemptionResults();

    for (;;) {}
}

static void taskPreemptionTest_2(void *pvParameters)
{
    for (;;)
    {   
        checkFlag = 1;
    }
}
#pragma GCC pop_options