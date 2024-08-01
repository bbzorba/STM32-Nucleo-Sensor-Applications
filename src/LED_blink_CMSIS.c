#include "stm32h7xx.h"

// Define LED pin and port
#define LED_PIN                     0   // Pin 0
#define LED_GPIO_PORT               GPIOB
#define LED_GPIO_CLK_ENABLE()       (RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN)

void delay(uint32_t delayCount);

int main(void) {
    // Enable the GPIO clock for the LED port
    LED_GPIO_CLK_ENABLE();

    // Configure the GPIO pin for the LED as output
    LED_GPIO_PORT->MODER &= ~(3UL << (LED_PIN * 2)); // Clear mode bits
    LED_GPIO_PORT->MODER |= (1UL << (LED_PIN * 2));  // Set mode to output

    // Main loop
    while (1) {
        // Toggle the LED pin using CMSIS
        LED_GPIO_PORT->ODR ^= (1UL << LED_PIN);
        
        // Delay
        delay(500000); // Adjust the delay count for the desired blink rate
    }
}

// Simple delay function
void delay(uint32_t delayCount) {
    while (delayCount--) {
        __NOP();
    }
}

