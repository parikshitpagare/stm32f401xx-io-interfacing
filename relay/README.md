![STM32 F401xx relay](https://user-images.githubusercontent.com/80714882/233423054-b8a212f8-35f7-45ca-995a-0ae4849ae8bd.png)

## Interfacing STM32 F401xx with Keypad
![Badge](https://img.shields.io/badge/STM32-F401-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![Badge](https://img.shields.io/badge/Cortex_M4-0091BD?style=for-the-badge&logo=arm&logoColor=white)

> **Note: STM32 Nucleo Board with F401xx microcontroller is used for interfacing. The programming is completely baremetal without the use of CubeMX software.** 

## Requirements

### Hardware

- STM32 F401xx based Nucleo Development Board
- Relay
- LED
- Resistor 220Ω

### Software

- STM32 Cube IDE

### Additional Code

- The `printf()` function cannot be executed by default. 
- Some additional code is added in "**Src\syscalls.c**" file which makes use of the SWO trace pin to print statements.

## Demo

https://github.com/parikshitpagare/stm32f401xx-io-interfacing/assets/80714882/eb831df2-270a-4d48-883e-9d3b364c308d

## Circuit Diagram

<img src="https://user-images.githubusercontent.com/80714882/233423365-dba0ac1a-a57a-407f-9fb1-1345b69d91ab.png"  width="70%" height="70%">


