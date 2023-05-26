/*
 * Interfacing Relay with STM32 F401xx
 *
 * Author: Parikshit Pagare
 * github.com/parikshitpagare
 * linkedin.com/in/parikshitpagare
 */

#include <stdio.h>
#include <stdint.h>

void delay(void);

int main(void) {

	/* AHB1 address */
	uint32_t *pRccahb1enr_addr = (uint32_t*)(0x40023800 + 0x30);

	/* GPIO registers address */
	uint32_t *pGpioA_modeReg_addr = (uint32_t*)(0x40020000 + 0x00);
	uint32_t *pGpioA_outputData_addr = (uint32_t*)(0x40020000 + 0x14);

	/* Enable clock for GPIO */
	*pRccahb1enr_addr |= (1 << 0);

	/* Configure mode of GPIO */
	*pGpioA_modeReg_addr &= ~(3 << 12); // Clear bit 12 and 13
	*pGpioA_modeReg_addr |= (1 << 12); // Set bit 12

	while(1) {
		/* Relay on */
		*pGpioA_outputData_addr |= (1 << 6);
		printf("LED ON\n");
		delay();

		/* Relay off */
		*pGpioA_outputData_addr &= ~(1 << 6);
		printf("LED OFF\n");
		delay();
	}
}

/* Delay using for loop */
void delay(void) {
	for( uint32_t delay = 0; delay < 4000000; delay++);
}
