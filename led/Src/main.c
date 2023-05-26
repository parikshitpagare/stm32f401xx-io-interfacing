/*
 * Interfacing LED with STM32 F401xx
 *
 * Author: Parikshit Pagare
 * github.com/parikshitpagare
 * linkedin.com/in/parikshitpagare
 */

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
	*pGpioA_modeReg_addr &= ~(3 << 10); // Clear bit 11 and 10
	*pGpioA_modeReg_addr |= (1 << 10); // Set bit 10

	while(1) {
		/* LED on */
		*pGpioA_outputData_addr |= (1 << 5);
		delay();

		/* LED off */
		*pGpioA_outputData_addr &= ~(1 << 5);
		delay();
	}
}

/* Delay using for loop */
void delay(void) {
	for( uint32_t delay = 0; delay < 4000000; delay++);
}
