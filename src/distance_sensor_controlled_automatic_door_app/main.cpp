#include "hcsr04.h"
#include "servo.h"
uint32_t distance = 0;

int main(void)
{
    HAL_Init();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_TIM4_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();

	//servo Pin
	pinStruct_t servoPin = {GPIOA,GPIO_PIN_3};
	static Servo servo(servoPin,TIM2,GPIO_AF1_TIM2,TIM_CHANNEL_4);

    //HCSR04 pins
    pinStruct_t trigPin = {GPIOC, GPIO_PIN_8};
    pinStruct_t echoPin = {GPIOC, GPIO_PIN_9};

    HCSR04_TrigPinPWMInit(trigPin, TIM3, GPIO_AF2_TIM3, TIM_CHANNEL_3);
    static HCSR04 hcsr04(echoPin, TIM3, GPIO_AF2_TIM3);

	while(1){
		if(hcsr04.GetDistance() < 50)
		{
			//fully open the door (move the servo to north) if the distance is less than 50 cm
			servo.TurnShaft(SERVO_NORTH);
		}
		else if (hcsr04.GetDistance() < 100 && hcsr04.GetDistance() > 50)
		{
			//half open the door (move the servo to east) if the distance is higher than 50 cm but less than 100 cm
			servo.TurnShaft(SERVO_EAST);
		}
		else{
			//close the door (move the servo to south) if the distance is higher than 100 cm
			servo.TurnShaft(SERVO_SOUTH);
		}
	}
	
}

extern "C" void SysTick_Handler(void)
{
    HAL_IncTick();
}