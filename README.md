# STM32-Nucleo-Applications

Basic STM32 Nucleo Applications using CMSIS and HAL libraries

In this reporistory, you will see some basic STM32 examples that were implemented using C and C++. Both HAL and CMSIS libraries are utilized to implement various algorithms on STM32 NUCLEO-H743ZI2 board. You can use any model of STM32 NUCLEO-H7 to implement this software in your environment. To use other STM32's, you need to include the library in the source code. For example you have a STM32F4-DISCOVERY board and want to develop software in this board, you simply have to link the library in your software as follows:

    #include "stm32f4xx.h"


PlatformIO tool of VS Code IDE is used to develop the software. Therefore, after installing VS Code, you need to install the following dependencies:

- C/C++ Extension: This extension provides C/C++ language support.
  
- Cortex-Debug Extension: This extension is used for debugging ARM Cortex-M microcontrollers.
  
- PlatformIO IDE: PlatformIO is an open-source ecosystem for IoT development, and it supports STM32 development.


You can install these extensions from the VS Code Marketplace. After installing PlatformIO, create a new project. Configure the project by editing the platformio.ini file. Modify the content of the file according to your platform, board and framework. The content of this file is as follows in our case:


    [env:nucleo_h743zi]
    platform = ststm32
    board = nucleo_h743zi
    framework = stm32cube


Build the source codes of the application from an example inside src folder by copying the content of the file (e.g. LED_blink_CMSIS.cpp) to your main.cpp file inside your project's src folder and upload it to the board.

P.S. Do not forget to include all the header files and source codes inside that application subfolder under the src folder in your project.