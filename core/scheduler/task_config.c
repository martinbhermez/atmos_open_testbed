#include "task_config.h"
#include "scheduler.h"

// Task Handles
TaskHandle_t BatteryTaskHandle = NULL;
TaskHandle_t PropulsionTaskHandle = NULL;
TaskHandle_t ThermalTaskHandle = NULL;
TaskHandle_t UITaskHandle = NULL;

// Task Functions (to be implemented in respective domains)
extern void BatteryTask(void *pvParameters);
extern void PropulsionTask(void *pvParameters);
extern void ThermalTask(void *pvParameters);
extern void UITask(void *pvParameters);

// Initialize and Create Tasks
void TaskConfig_Init(void) {
    // Create Battery Task
    Scheduler_AddTask(BatteryTask, "BatteryTask", STACK_DEPTH_BATTERY, NULL, TASK_PRIORITY_BATTERY, &BatteryTaskHandle);

    // Create Propulsion Task
   // Scheduler_AddTask(PropulsionTask, "PropulsionTask", STACK_DEPTH_PROPULSION, NULL, TASK_PRIORITY_PROPULSION, &PropulsionTaskHandle);

    // Create Thermal Task
    //Scheduler_AddTask(ThermalTask, "ThermalTask", STACK_DEPTH_THERMAL, NULL, TASK_PRIORITY_THERMAL, &ThermalTaskHandle);

    // Create UI Task
  //  Scheduler_AddTask(UITask, "UITask", STACK_DEPTH_UI, NULL, TASK_PRIORITY_UI, &UITaskHandle);
}

