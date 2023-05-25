![Keypad](https://user-images.githubusercontent.com/80714882/232504315-d153a301-703b-4692-905c-0fe6e0cf2498.png)

## Interfacing STM32 F401xx with Keypad
![Badge](https://img.shields.io/badge/STM32-F401-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![Badge](https://img.shields.io/badge/Cortex_M4-0091BD?style=for-the-badge&logo=arm&logoColor=white)

> **Note: STM32 Nucleo Board with F401xx microcontroller is used for interfacing. The programming is completely baremetal without the use of CubeMX software.** 

## Requirements

### Hardware

- STM32 F401xx based Nucleo Development Board
- 4x4 Membrane Keypad

### Software

- STM32 Cube IDE

### Additional Code

- The `printf()` function cannot be executed by default. 
- Some additional code is added in "**Src\syscalls.c**" file which makes use of the SWO trace pin to print statements.

## Demo

https://user-images.githubusercontent.com/80714882/233170488-46b39b8d-ad29-4127-aeb2-9eb614582909.mp4

## Circuit Diagram

<img src="https://user-images.githubusercontent.com/80714882/232569183-c1f0748b-c357-4fe6-adc0-abda0b615434.png"  width="70%" height="70%">
