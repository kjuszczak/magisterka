#include "task_switch.h"

/* Board management API */
#include "board_config.h"

/* RTOS API */
#include "rtos_portable.h"

#define TEST_ITERATION 1000000

/* TASK PARAMS */
#define TASK_PRIORITY   0

static struct TaskSwitchResults testResults = {
    .loopCmdTime = 0,
    .testTime = 0,
    .testIteration = 2 * TEST_ITERATION
};

static void initTest();
static void taskSwitchTest_1(void *pvParameters);
static void taskSwitchTest_2(void *pvParameters);

void startTaskSwitchTest()
{
    createTask(taskSwitchTest_1, "TaskSwitchTest_1", TASK_PRIORITY);
}

void printTestSwitchResults()
{
    static uint32_t result = 0;
    result = testResults.testTime - testResults.loopCmdTime;
    print("Task switch test: loopCmdTime:%u, testTime:%u, result:%u\n",
        testResults.loopCmdTime,
        testResults.testTime,
        result);
}

struct TaskSwitchResults* getTestSwitchResults()
{
    return &testResults;
}

#pragma GCC push_options
#pragma GCC optimize ("O0")
static void initTest()
{
    startTimer();
    for (uint32_t i = 0; i < TEST_ITERATION; i++)
    {
        ; /* JUST LOOP */
    }
    for (uint32_t i = 0; i < TEST_ITERATION; i++)
    {
        ; /* JUST LOOP */
    }
    testResults.loopCmdTime = getTimerValue();
    stopTimer();
}

static void taskSwitchTest_1(void *pvParameters)
{
    initTest();

    createTask(taskSwitchTest_2, "TaskSwitchTest_2", TASK_PRIORITY);

    startTimer();
    for (uint32_t i = 0; i < TEST_ITERATION; i++)
    {
        switchTask();
    }
    testResults.testTime = getTimerValue();
    stopTimer();

    printTestSwitchResults();

    for (;;) {}
}

static void taskSwitchTest_2(void *pvParameters)
{
    for (uint32_t i = 0; i < TEST_ITERATION; i++)
    {
        switchTask();
    }

    for (;;) {}
}
#pragma GCC pop_options