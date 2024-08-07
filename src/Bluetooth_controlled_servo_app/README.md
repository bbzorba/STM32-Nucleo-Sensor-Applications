# Bluetooth Controlled Servo Application

## Hardware Connections

### HC05 - STM32 Connection

HC05 Bluetooth Module  |      STM32H743ZI2 Nucleo board

VCC         <->     3.3V

GND         <->     GND

TX Pin   <->     RX Pin (PC11)

### Servo - STM32 Connection

Servo Motor  |      STM32H743ZI2 Nucleo board 

VCC         <->     5V

GND         <->     GND

Servo Pin   <->     A0 (PA3) 


## Software Modifications

As told in HC05 Bluetooth application and servo motor control application, the correct UART RX pin and servo pin on the STM32 must be selected and their corresponding GPIO clocks must be enabled. To achieve this, the following lines in main.cpp file must be modified to use this application on another board.

    __HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_USART3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	
	pinStruct_t servoPin = {GPIOA,GPIO_PIN_3};
	pinStruct_t uartRxPin = {GPIOC,GPIO_PIN_11};
	static Servo servo(servoPin,TIM2,GPIO_AF1_TIM2,TIM_CHANNEL_4);
	static HC05 hc05(uartRxPin,USART3,9600,GPIO_AF7_USART3,UART_MODE_RX);