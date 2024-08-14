#include "hcsr04.h"

uint32_t distance = 0;

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_TIM4_CLK_ENABLE();

    //Sensor pins
    pinStruct_t trigPin = {GPIOC, GPIO_PIN_8};
    pinStruct_t echoPin = {GPIOC, GPIO_PIN_9};

    HCSR04_TrigPinPWMInit(trigPin, TIM3, GPIO_AF2_TIM3, TIM_CHANNEL_3);
    static HCSR04 hcsr04(echoPin, TIM3, GPIO_AF2_TIM3);

    while(1)
    {
        distance = hcsr04.GetDistance();
    }
}

extern "C" void SysTick_Handler(void)
{
    HAL_IncTick();
}