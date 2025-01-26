#include "FreeRTOS.h"
#include "task.h"

void main_task(void *pvParameters) {
    while (1) {
        // Main task loop
    }
}

int main(void) {
    xTaskCreate(main_task, "MainTask", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    // Should never reach here
    while (1);
}
