/*
 * Interfacing 4x4 Keypad with STM32 F401xx
 *
 * Author: Parikshit Pagare
 * github.com/parikshitpagare
 * linkedin.com/in/parikshitpagare
 */

#include <stdio.h>
#include <stdint.h>

void delay (void);

int main(void) {

	/* AHB1 address */
	uint32_t volatile *const pRccahb1enr_addr = (uint32_t*)(0x40023800 + 0x30);

	/* GPIO registers address */
	uint32_t volatile *const pGpioA_modeReg_addr = (uint32_t*)(0x40020000 + 0x00);
	uint32_t volatile *const pGpioA_inputData_addr = (uint32_t*)(0x40020000 + 0x10);
	uint32_t volatile *const pGpioA_pullupDown_addr = (uint32_t*)(0x40020000 + 0x0C);

	/* Enable clock for GPIO */
	*pRccahb1enr_addr |= (1 << 0);

	/* Configure registers of GPIO */

	/* Input mode */
	*pGpioA_modeReg_addr &= ~(3 << 12);

	/* Configure pull up/down of GPIO */
	*pGpioA_pullupDown_addr &= ~(3 << 12);
	*pGpioA_pullupDown_addr |= (2 << 12);

	while (1) {

		if (!(*pGpioA_inputData_addr & (1 << 6))) {
			delay();
			printf("Button not pressed\n");
		}
		else if (*pGpioA_inputData_addr & (1 << 6)) {
			delay();
			printf("Button pressed\n");
		}
	}
}

	/* Delay using for loop for switch debouncing */
void delay (void) {
	for (int32_t i = 0; i < 300000; i++);
}
