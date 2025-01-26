#include "scheduler.h"
#include "FreeRTOS.h"
#include "task.h"

// Scheduler Initialization
void Scheduler_Init(void) {
    // Perform any scheduler-related initialization here
    // This could include setting up system resources, logging, etc.
}

// Start the FreeRTOS Scheduler
void Scheduler_Start(void) {
    vTaskStartScheduler();
    // Should never return, unless there's an error
    for (;;) {}
}

// Add a new task to the scheduler
BaseType_t Scheduler_AddTask(TaskFunction_t taskFunction, const char *name, uint16_t stackDepth, void *parameters, UBaseType_t priority, TaskHandle_t *taskHandle) {
    return xTaskCreate(taskFunction, name, stackDepth, parameters, priority, taskHandle);
}
