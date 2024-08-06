#include "stm32h7xx_hal.h"

// Define LED pin and port
#define LED_PIN                     GPIO_PIN_1 // Ensure this matches your board's LED pin
#define LED_GPIO_PORT               GPIOB
#define LED_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()

int main(void) {
    // Initialize the HAL Library
    HAL_Init();

    // Enable the GPIO clock for the LED port
    LED_GPIO_CLK_ENABLE();

    // Initialize the GPIO pin for the LED
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin     = LED_PIN;
    GPIO_InitStruct.Mode    = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull    = GPIO_NOPULL;
    GPIO_InitStruct.Speed   = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

    // Main loop
    while (1) {
        // Toggle the LED
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(500); // 500 ms delay
    }
}
