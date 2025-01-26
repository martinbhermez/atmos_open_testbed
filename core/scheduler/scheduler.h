#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "FreeRTOS.h"
#include "task.h"

// Scheduler Initialization
void Scheduler_Init(void);

// Function to start the scheduler
void Scheduler_Start(void);

// Add a new task to the scheduler
BaseType_t Scheduler_AddTask(TaskFunction_t taskFunction, const char *name, uint16_t stackDepth, void *parameters, UBaseType_t priority, TaskHandle_t *taskHandle);

#endif // SCHEDULER_H
