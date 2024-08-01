# STM32-Nucleo-Applications
Basic STM32 Nucleo Applications using CMSIS and HAL libraries

In this reporisotry, you will see some basic STM32 examples that were implemented using C and C++. Both HAL and CMSIS libraries are utilized to implement various algorithms on STM32 NUCLEO-H743ZI2 board. You can use any model of STM32 NUCLEO-H7 to implement this software in your environment. To use other STM32's, you need to include the library in the source code. For example you have a STM32F4-DISCOVERY board and want to develop software in this board, you simply have to link the library in your software as follows:
#include "stm32h7xx.h"


PlatformIO tool of VS Code IDE is used to develop the software. Therefore, after installing VS Code, you need to install the following dependencies:

- C/C++ Extension: This extension provides C/C++ language support.
  
- Cortex-Debug Extension: This extension is used for debugging ARM Cortex-M microcontrollers.
  
- PlatformIO IDE: PlatformIO is an open-source ecosystem for IoT development, and it supports STM32 development.

