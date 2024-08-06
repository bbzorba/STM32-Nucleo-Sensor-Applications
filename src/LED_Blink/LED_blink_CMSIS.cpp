#include "stm32h7xx.h"

// Define LED pin and port
#define LED_PIN                     0   // Pin 0
#define LED_GPIO_PORT               GPIOB

class LED {
public:
    LED(uint16_t pin) : pin_(pin) {
        enableClock();
        configureGPIO();
    }

    void toggle(){
        LED_GPIO_PORT->ODR ^= (1UL << LED_PIN);
    }

    void delay_func(uint32_t delayCount) {
        while (delayCount--) {
            __NOP();
        }
    }

private:
    uint16_t pin_;

    void enableClock() {
        RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN; // Enable clock for GPIOB
    }

    void configureGPIO() {
        // Configure GPIO pin as output
        LED_GPIO_PORT->MODER &= ~(3UL << (pin_ * 2)); // Clear mode bits
        LED_GPIO_PORT->MODER |= (1UL << (pin_ * 2));  // Set mode to output
    }
};

int main(void) {
    LED led(LED_PIN);

    // Main loop
    while (1) {
        led.toggle();
        led.delay_func(5000000);
        
    }
}

