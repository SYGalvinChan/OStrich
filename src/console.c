#include "console.h"

void console_init() {
	mini_uart_init();
}

void console_write(char* str) {
	char c = str[0];
	while (c) {
		mini_uart_tx(c);
	}
}

char* console_readline() {
	// TODO
	return 0x00;
}


