#include "mini_uart.h"
#include "utils.h"
#include "memory_map.h"

void mini_uart_init() {
	unsigned int register_value;

	// Sets GPIO Pin 14 and 15 to alternative function 5 for UART1 TXD/RXD
	register_value = READ_REG_32(GPFSEL1);
	register_value = register_value & ~(0b111 << 12);
	register_value = register_value | 0b010 << 12;
	register_value = register_value & ~(0b111 << 15);
	register_value = register_value | 0b010 << 15;
	WRITE_REG_32(GPFSEL1, register_value);

	// Sets Pull Up/Pull Down resistor for GPIO Pin 14 and 15 to none
	register_value = READ_REG_32(GPIO_PUP_PDN_CNTRL_REG0);
	register_value = register_value & ~(0b11 << 28);
	register_value = register_value | 0b00 << 28;
	register_value = register_value & ~(0b11 << 30);
	register_value = register_value | 0b00 << 30;
	WRITE_REG_32(GPIO_PUP_PDN_CNTRL_REG0, register_value);

	// Enable Mini UART
	register_value = READ_REG_32(AUX_ENABLES);
	register_value = register_value & ~(0b1);
	register_value = register_value | (0b1);
	WRITE_REG_32(AUX_ENABLES, register_value);

	// Disable extra controls, transmit and receive for now
	WRITE_REG_32(AUX_MU_CNTL_REG, 0);
	
	// Disable transmit and receive interupts 
	register_value = READ_REG_32(AUX_MU_IER_REG);
	register_value = register_value & ~(0b11);
	WRITE_REG_32(AUX_MU_IER_REG, register_value);

	// Set data size to 8 bits and allow access to baudrate register
	WRITE_REG_32(AUX_MU_LCR_REG, 1);

	// Set baudrate to 115200
	WRITE_REG_32(AUX_MU_BAUD_REG, 270);

	// Enable transmit and receive
	WRITE_REG_32(AUX_MU_CNTL_REG, 0b11);
}

void mini_uart_tx(char c) {
	while (1) {
		if (READ_REG_32(AUX_MU_LSR_REG) & 0x30) {
			WRITE_REG_32(AUX_MU_IO_REG, c);
			break;
		}
	}

}

char mini_uart_rx() {
	char c;
	while (1) {
		if (READ_REG_32(AUX_MU_LSR_REG) & 0x01) {
			c = (char) READ_REG_32(AUX_MU_IO_REG);
			break;
		}
	}
	return c;
}


