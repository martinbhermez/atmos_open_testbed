#ifndef TASK_CONFIG_H
#define TASK_CONFIG_H

#include "FreeRTOS.h"
#include "task.h"

// Task Priorities
#define TASK_PRIORITY_BATTERY     (2)
#define TASK_PRIORITY_PROPULSION  (3)
#define TASK_PRIORITY_THERMAL     (2)
#define TASK_PRIORITY_UI          (1)

// Stack Depths
#define STACK_DEPTH_BATTERY       (configMINIMAL_STACK_SIZE + 100)
#define STACK_DEPTH_PROPULSION    (configMINIMAL_STACK_SIZE + 150)
#define STACK_DEPTH_THERMAL       (configMINIMAL_STACK_SIZE + 100)
#define STACK_DEPTH_UI            (configMINIMAL_STACK_SIZE + 50)

// Task Handles
extern TaskHandle_t BatteryTaskHandle;
extern TaskHandle_t PropulsionTaskHandle;
extern TaskHandle_t ThermalTaskHandle;
extern TaskHandle_t UITaskHandle;

#endif // TASK_CONFIG_H
