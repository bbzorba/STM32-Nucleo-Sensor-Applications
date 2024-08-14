#include "motor.h"

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();

    pinStruct_t motorPin1 = {GPIOC, GPIO_PIN_8};
    pinStruct_t motorPin2 = {GPIOC, GPIO_PIN_10};
    pinStruct_t enablePin = {GPIOC, GPIO_PIN_9};
    static Motor motor(motorPin1, motorPin2, enablePin, TIM3, GPIO_AF2_TIM3, TIM_CHANNEL_4);

    while (1)
    {
        motor.MoveForward(MOTOR_FULLSPEED);
        HAL_Delay(2000);        // Run for 2 seconds

        motor.MoveForward(MOTOR_HALFSPEED);
        HAL_Delay(2000);        // Run for 2 seconds
    }
}
