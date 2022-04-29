#include "scenario.h"

/* Board management API */
#include "board_config.h"

/* RTOS API */
#include "rtos_portable.h"

#define TEST_ITERATION      1000
#define TASK_PERIOD         5 // ms
#define TASK_2_PERIOD       10 // ms

static void taskPeriodic(void *pvParameters);
static void taskJitter_1(void *pvParameters);
static void taskJitter_2(void *pvParameters);
static void taskPeriodic_2(void *pvParameters);

static uint32_t testTime[TEST_ITERATION + 1];
static uint32_t loopIndex = 0;

static const char* testScenario;

void startJitterTestScenario(uint8_t taskPriority_1, uint8_t taskPriority_2, uint8_t periodicTaskPriority, const char* testScenarioName)
{
    testScenario = testScenarioName;

    createPeriodicTask(taskPeriodic, "TaskPeriodic", TASK_PERIOD, periodicTaskPriority, 0);
    startTimer();

    createTask(taskJitter_1, "TaskJitter_1", taskPriority_1, TASK_1_INDEX);
    createTask(taskJitter_2, "TaskJitter_2", taskPriority_2, TASK_2_INDEX);
}

void addSecondPeriodicTask(uint8_t periodicTaskPriority)
{
    createPeriodicTask(taskPeriodic_2, "TaskPeriodic_2", TASK_2_PERIOD, periodicTaskPriority, 1);
}

void printJitterTestResults()
{
    print("Jitter test %s: testTime:%u\n", testScenario, testTime[1000] - testTime[999]);
}

#pragma GCC push_options
#pragma GCC optimize ("O0")

static void taskPeriodic(void *pvParameters)
{
    testTime[loopIndex] = getTimerValue();

    if (loopIndex == TEST_ITERATION)
    {
        deletePeriodicTask(0);
        deletePeriodicTask(1);
        stopTimer();
        printJitterTestResults();
    }
    loopIndex++;
}

static void taskJitter_1(void *pvParameters)
{
    for (;;) {}
}

static void taskJitter_2(void *pvParameters)
{
    for (;;) {}
}

static void taskPeriodic_2(void *pvParameters)
{
    for (uint16_t i = 0; i < 1000; i++) {}
}

#pragma GCC pop_options
