#include "console.h"
#include "mini_uart.h"

#define MAX_BUFFER_SIZE  0x100
static char buffer[MAX_BUFFER_SIZE]; // Stores characters read from Mini UART to be returned by console_readline()

void console_init() {
	mini_uart_init();
}

void console_write(char* str) {
	char* c = str;
	while (*c) {
		mini_uart_tx(*c);
		c++;		
	}
}

char* console_readline() {
	char c;
	int i = 0;
	c = mini_uart_rx();
	while (c != '\n') {
		if (i >= MAX_BUFFER_SIZE - 1) {
			break;
		}
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	return buffer;
}
