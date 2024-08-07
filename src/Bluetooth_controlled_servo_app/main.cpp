#include "hc05.h"
#include "servo.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_USART3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	
	pinStruct_t servoPin = {GPIOA,GPIO_PIN_3};
	pinStruct_t uartRxPin = {GPIOC,GPIO_PIN_11};
	static Servo servo(servoPin,TIM2,GPIO_AF1_TIM2,TIM_CHANNEL_4);
	static HC05 hc05(uartRxPin,USART3,9600,GPIO_AF7_USART3,UART_MODE_RX);
	
	while(1)
	{ 
		bluetoothData = hc05.GetChar();
		switch(bluetoothData)
		{
			case 'l':
			case 'L':
				servo.TurnShaft(SERVO_NORTH);
				break;
			case 'm':
			case 'M':
				servo.TurnShaft(SERVO_EAST);
				break;
			case 'r':
			case 'R':
				servo.TurnShaft(SERVO_SOUTH);
				break;
		}
	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}

