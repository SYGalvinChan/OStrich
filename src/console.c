#include "console.h"
#include "mini_uart.h"

#define MAX_BUFFER_SIZE  100
static char buffer[MAX_BUFFER_SIZE]; // Stores characters read from Mini UART to be returned by console_readline()

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
	char c;
	int i = 0;
	c = mini_uart_rx();
	while (c != '\n') {
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	return buffer;
}
