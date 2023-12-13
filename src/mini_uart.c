#include "mini_uart.h"
#include "utils.h"
#include "gpio.h"
#include "memory_map/aux.h"
#include "memory_map/gpio.h"

#include <stdint.h>

void mini_uart_init() {
	uint32_t register_value;

	// Sets GPIO Pin 14 and 15 to alternative function 5 for UART1 TXD/RXD
	gpio_set_func(14, GPIO_FUNC_ALT_FUNC_5);
	gpio_set_func(15, GPIO_FUNC_ALT_FUNC_5);

	// Sets Pull Up/Pull Down resistor for GPIO Pin 14 and 15 to none
	gpio_set_pull_state(14, GPIO_PULL_NONE);
	gpio_set_pull_state(15, GPIO_PULL_NONE);

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


