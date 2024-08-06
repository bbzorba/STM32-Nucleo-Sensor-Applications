# Servo Motor Application


Hardware Connections:


Servo Motor  |      STM32 

VCC         <->     5V

GND         <->     GND

Servo Pin   <->     PA3


PA3 is also the A0 pin of STM32H743ZI2 Nucleo board. PWM is applied using the Channel 4 of Timer 2.


Understanding the PWM Values:

PWM (Pulse Width Modulation) signal is used to control the position of the servo motor. The pulse width (duration) determines the position of the servo.

-Pulse Width (ms): This is the duration for which the PWM signal stays high in one cycle.

-Period (ms): This is the duration of one complete cycle of the PWM signal (high and low).


In most servo applications, the PWM period is around 20ms (50Hz frequency), and the pulse width varies between 1ms (0 degrees) to 2ms (180 degrees) to control the position of the servo shaft.


Calculating PWM Values:

-Clock Frequency: Assume the TIM2 clock source is set to 100 MHz (HCLK/4 with HCLK at 400 MHz).

-Prescaler: The prescaler divides the timer clock. In the code provided, the prescaler is set to 9 (htim2.Init.Prescaler = 10 - 1;), which divides the clock by 10.

-Counter Period: This value determines the period of the PWM signal.


The period of the PWM can be calculated as:

    PWM Period=(Prescaler+1)×(Counter Period+1)/Timer Clock Frequency


For the provided values:

Prescaler: 10
Counter Period: 10000

    PWM Period=(10)×(10000)/100×106=1 ms

However, to achieve a 20ms period, the Counter Period should be 20000 (for a 10kHz clock frequency post-prescaler). This makes the configuration:

    PWM Period=20000×10−5 s=0.2 s=20 ms


Adjusting Values:

To correct the configuration to achieve 20ms PWM period:

-Set the timer clock to 100 MHz.
-Set the prescaler to 1000 - 1.
-Set the counter period to 20000 - 1 to get 20ms period.


Recalculating Pulse Widths:

To achieve specific pulse widths (in ms) based on counter period (20000):

-SERVO_NORTH: 1 ms pulse width

-SERVO_EAST: 10 ms pulse width

-SERVO_SOUTH: 20 ms pulse width


These should map as follows:

    SERVO_NORTH: (1ms / 20ms) * 20000 = 1000
    SERVO_EAST: (10ms / 20ms) * 20000 = 10000
    SERVO_SOUTH: (20ms / 20ms) * 20000 = 20000