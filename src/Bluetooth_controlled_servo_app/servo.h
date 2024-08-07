#ifndef SERVO_H
#define SERVO_H

#include "pinmap.h"

enum 
{
	SERVO_NORTH = 1000,
	SERVO_EAST = 10000,
	SERVO_SOUTH = 20000
};

class Servo
{
	private:
		TIM_HandleTypeDef htim;
		uint8_t pwmCh;
	public:
		Servo(pinStruct_t& servoPin,
				  TIM_TypeDef* TIMx,
				  uint8_t gpioAFSelTIMx,
				  uint8_t pwmChannel);
		void TurnShaft(uint32_t position);
};

#endif //SERVO_H
