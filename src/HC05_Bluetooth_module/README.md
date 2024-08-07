# HC05 Bluetooth Communication Application

## Hardware Connections

HC05 Bluetooth Module  |      STM32H743ZI2 Nucleo board

VCC         <->     3.3V

GND         <->     GND

TX Pin   <->     RX Pin (PC11)


## Software Modifications

To receive a data from the the bluetooth module, we do not need the TX pin of the STM32 to be connected. We only need the RX pin of UART1 comunication on STM32 board to be connected to receive data, which is defined in main.cpp code. RX pin of UART1 belongs to PC_11 pin on STM32H743ZI2 Nucleo board. Therefore, if you are using another STM32 board, you need to connect the bluetooth module to the correct UART RX pin on the STM32 (by reading the datasheet/user manual) and modify the main.cpp file to enable the corresponding GPIO clock and UART pin.
