#include "servo.h"

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	
	pinStruct_t servoPin = {GPIOA,GPIO_PIN_3};
	static Servo servo(servoPin,TIM2,GPIO_AF1_TIM2,TIM_CHANNEL_4);
	
	while(1)
	{
		//Turn servo shaft in the following sequence repeatedly:
		//MID-LEFT-MID-RIGHT
		servo.TurnShaft(SERVO_NORTH);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_EAST);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_SOUTH);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_EAST);
		HAL_Delay(1000);
	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}
