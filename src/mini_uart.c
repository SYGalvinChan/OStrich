#include "mini_uart.h"
#include "utils.h"
#include "gpio.h"
#include "memory_map/aux.h"
#include "memory_map/gpio.h"

#include <stdint.h>

void mini_uart_init() {

	// Enable Mini UART
	WRITE_REG_32(AUX_ENABLES, 1);

	// Disable transmit and receive interupts 
	WRITE_REG_32(AUX_MU_IER_REG, 0);

	// Disable extra controls, transmit and receive for now
	WRITE_REG_32(AUX_MU_CNTL_REG, 0);

	// Set data size to 8 bits and allow access to baudrate register
	WRITE_REG_32(AUX_MU_LCR_REG, 3);

    // Set RTS to high
    WRITE_REG_32(AUX_MU_MCR_REG, 0);

	// Disable transmit and receive interupts 
	WRITE_REG_32(AUX_MU_IER_REG, 0);

	// Dunno
	WRITE_REG_32(AUX_MU_IIR_REG, 0xC6);

	// Set baudrate to 115200
	WRITE_REG_32(AUX_MU_BAUD_REG, ((500000000/(115200*8))-1));

	// Sets GPIO Pin 14 and 15 to alternative function 5 for UART1 TXD/RXD
	gpio_set_func(14, GPIO_FUNC_ALT_FUNC_5);
	gpio_set_func(15, GPIO_FUNC_ALT_FUNC_5);

	// Sets Pull Up/Pull Down resistor for GPIO Pin 14 and 15 to none
	gpio_set_pull_state(14, GPIO_PULL_NONE);
	gpio_set_pull_state(15, GPIO_PULL_NONE);

	// Enable transmit and receive
	WRITE_REG_32(AUX_MU_CNTL_REG, 3);
}

void mini_uart_tx(char c) {
    while (!(READ_REG_32(AUX_MU_LSR_REG) & 0x20));
    WRITE_REG_32(AUX_MU_IO_REG, (uint32_t) c);
}

char mini_uart_rx() { 
	while (!(READ_REG_32(AUX_MU_LSR_REG) & 0x01));
	return (char) READ_REG_32(AUX_MU_IO_REG);
}


