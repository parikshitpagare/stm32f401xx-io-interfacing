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
	uint32_t volatile *const pGpioA_outputData_addr = (uint32_t*)(0x40020000 + 0x14);
	uint32_t volatile *const pGpioA_pullupDown_addr = (uint32_t*)(0x40020000 + 0x0C);

	/* Enable clock for GPIO */
	*pRccahb1enr_addr |= (1 << 0);

	/* Configure registers of GPIO */

	/* Input mode (coloumn) */
	*pGpioA_modeReg_addr &= ~(0xFF << 12);

	/* Output mode (rows) */
	*pGpioA_modeReg_addr &= ~(0XF << 0);
	*pGpioA_modeReg_addr |= (5 << 0);
	*pGpioA_modeReg_addr &= ~(0XF << 8);
	*pGpioA_modeReg_addr |= (5 << 8);

	/* Configure pull up/down of GPIO */
	*pGpioA_pullupDown_addr &= ~(0xFF << 12);
	*pGpioA_pullupDown_addr |= (0x55 << 12);

	while (1) {
		/* Make rows high */
		*pGpioA_outputData_addr |= (3 << 0);
		*pGpioA_outputData_addr |= (3 << 4);

		/******************************************************************/

		/* Make R1 Low */
		*pGpioA_outputData_addr &= ~(1 << 0);

		/* Check C1 */
		if (!(*pGpioA_inputData_addr & (1 << 6))) {
			delay();
			printf("1\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 7))) {
			delay();
			printf("2\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 8))) {
			delay();
			printf("3\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 9))) {
			delay();
			printf("A\n");
		}

		/******************************************************************/

		/* Make R2 Low */
		*pGpioA_outputData_addr |= (3 << 0);
		*pGpioA_outputData_addr |= (3 << 4);
		*pGpioA_outputData_addr &= ~(1 << 1);

		/* Check C2 */
		if (!(*pGpioA_inputData_addr & (1 << 6))) {
			delay();
			printf("4\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 7))) {
			delay();
			printf("5\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 8))) {
			delay();
			printf("6\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 9))) {
			delay();
			printf("B\n");
		}

		/******************************************************************/

		/* Make R3 Low */
		*pGpioA_outputData_addr |= (3 << 0);
		*pGpioA_outputData_addr |= (3 << 4);
		*pGpioA_outputData_addr &= ~(1 << 4);

		/* Check C2 */
		if (!(*pGpioA_inputData_addr & (1 << 6))) {
			delay();
			printf("7\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 7))) {
			delay();
			printf("8\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 8))) {
			delay();
			printf("9\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 9))) {
			delay();
			printf("C\n");
		}

		/******************************************************************/

		/* Make R4 Low */
		*pGpioA_outputData_addr |= (3 << 0);
		*pGpioA_outputData_addr |= (3 << 4);
		*pGpioA_outputData_addr &= ~(1 << 5);

		/* Check C2 */
		if (!(*pGpioA_inputData_addr & (1 << 6))) {
			delay();
			printf("START\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 7))) {
			delay();
			printf("0\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 8))) {
			delay();
			printf("STOP\n");
		}
		if (!(*pGpioA_inputData_addr & (1 << 9))) {
			delay();
			printf("D\n");
		}
	}
}

/* Delay using for loop for switch debouncing */
void delay (void) {
	for (int32_t i = 0; i < 300000; i++);
}
