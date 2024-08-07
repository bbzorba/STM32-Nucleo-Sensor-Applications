#include "hc05.h"

char bluetoothData = '\0';

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_USART3_CLK_ENABLE();
	
	pinStruct_t uartRxPin = {GPIOC,GPIO_PIN_11};
	static HC05 hc05(uartRxPin,USART3,9600,GPIO_AF7_USART3,UART_MODE_RX);
	
	while(1)
	{
		bluetoothData = hc05.GetChar();
	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}

