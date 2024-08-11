# Servo Motor Control Application


### Servo Motor - STM32H743ZI2 Nucleo Board Connection

| Servo | STM32 |
|----------|----------|
| VCC	| 5V |
| GND	| GND |
| Servo Pin	| A0 (PA3) |


## Software Modifications

PA3 is also the A0 pin of STM32H743ZI2 Nucleo board. PWM is applied using the Channel 4 of Timer 2. While implementing this application on a board other than STM32H743ZI2, do not forget to modify the pin number (e.g. GPIO_PIN_3), port number (GPIOA), the clock and timer that is used by the pin you selected in main.cpp file. You also might need to assign different values to PWM signals since the frequency of the timer you use might be different. In that case, modify the SERVO_NORTH, SERVO_EAST and SERVO_SOUTH values under servo.h file.


## Understanding the PWM Values

PWM (Pulse Width Modulation) signal is used to control the position of the servo motor. The pulse width (duration) determines the position of the servo.

- Pulse Width (ms): This is the duration for which the PWM signal stays high in one cycle.

- Period (ms): This is the duration of one complete cycle of the PWM signal (high and low).


In most servo applications, the PWM period is around 20ms (50Hz frequency), and the pulse width varies between 1ms (0 degrees) to 2ms (180 degrees) to control the position of the servo shaft.


## Calculating PWM Values for TIM2

For controlling a servo motor with a PWM signal, the standard PWM frequency is 50 Hz, which corresponds to a period of 20 milliseconds (ms).
System and Timer Configuration

- System Clock (SYSCLK): 400 MHz (using PLL)
- Prescaler: 1999
- Timer Clock: 400 MHz / (1999 + 1) = 200 kHz

### PWM Period Calculation

To generate a 20 ms period with a timer clock of 200 kHz:

PWM Period (ARR) = Timer Clock / PWM Frequency = 200,000 Hz / 50 Hz = 4000

So, the Period value should be set to 4000 - 1 for a 20 ms period.

### PWM Pulse Widths

The pulse widths in milliseconds (ms) for the PWM signal need to be converted to timer counts.

- SERVO_NORTH (1 ms pulse width): (5 ms / 20 ms) × 4000 = 1000
- SERVO_EAST (10 ms pulse width): (50 ms / 20 ms) × 4000 = 10000
- SERVO_SOUTH (20 ms pulse width): (100 ms / 20 ms) × 4000 = 20000