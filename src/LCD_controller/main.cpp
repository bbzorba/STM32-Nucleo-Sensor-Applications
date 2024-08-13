#include "lcd.h"

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	pinStruct_t rs = {GPIOE,GPIO_PIN_9};
	pinStruct_t en = {GPIOE,GPIO_PIN_11};
	pinStruct_t d4 = {GPIOE,GPIO_PIN_14};
	pinStruct_t d5 = {GPIOE,GPIO_PIN_13};
	pinStruct_t d6 = {GPIOE,GPIO_PIN_8};
	pinStruct_t d7 = {GPIOE,GPIO_PIN_7};
	
	static LCD lcd(rs,en,d4,d5,d6,d7);
	
	
	while(1)
	{
		lcd.Print("Hello world!");
		HAL_Delay(1000);
		lcd.Clear();
		HAL_Delay(1000);
		lcd.Print("Random Stuff:");
		lcd.SetCursor(1,0);
		lcd.Print("!'^+%&/()=?_;");
		HAL_Delay(1000);
		lcd.Clear();
	}
	
}

extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}

