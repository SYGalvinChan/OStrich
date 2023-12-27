#include "console.h"
#include "HAL/mini_uart.h"
#include "printf.h"

void console_init() {
	mini_uart_init();
	init_printf(0, putc);
}

void console_write(char* str) {
	char* c = str;
	while (*c) {
		mini_uart_tx(*c);
		c++;		
	}
}