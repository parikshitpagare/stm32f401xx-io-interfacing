![STM32 F401xx Push button](https://user-images.githubusercontent.com/80714882/233236624-b2eb2f70-b8d4-4f19-b3de-49320fe0032a.png)

## Interfacing STM32 F401xx with Keypad
![Badge](https://img.shields.io/badge/STM32-F401-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![Badge](https://img.shields.io/badge/Cortex_M4-0091BD?style=for-the-badge&logo=arm&logoColor=white)

> **Note: STM32 Nucleo Board with F401xx microcontroller is used for interfacing. The programming is completely baremetal without the use of CubeMX software.** 

## Requirements

### Hardware

- STM32 F401xx based Nucleo Development Board
- Push Button

### Software

- STM32 Cube IDE

### Additional Code

- The `printf()` function cannot be executed by default. 
- Some additional code is added in "**Src\syscalls.c**" file which makes use of the SWO trace pin to print statements.

## Demo

https://user-images.githubusercontent.com/80714882/233237605-094abcad-efd9-451f-bbf1-99e27e745c47.mp4

## Circuit Diagram

> **Note: No external pull up/pull down resistor is required. Internal pull down resistor is configured in the program.**

<img src="https://user-images.githubusercontent.com/80714882/233237572-596e1537-fa49-4660-8337-cd8d9d2eab89.png"  width="65%" height="65%">


