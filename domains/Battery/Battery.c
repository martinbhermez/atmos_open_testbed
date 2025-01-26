#include "Battery.h"
#include "stm32f4xx_hal_gpio.h"  // Example: Using GPIO for status indication

void BatteryTask(void *pvParameters) {
    (void)pvParameters;

    while (1) {
        // Simulate checking battery health
 //       GPIO_TogglePin(GPIOB, GPIO_PIN_0);  // Example: Toggle LED for battery status
        HAL_GPIO_TogglePin(GPIOB, 1); // Example: Toggle LED for battery status

        vTaskDelay(pdMS_TO_TICKS(1000));    // Delay for 1 second

    }
}
