#include "console.h"
#include "printf.h"
#include <stdint.h>

int current_EL();

void main(void) {

	console_init();
	console_write("Console initialized!!!!\r\n");
	printf("Current Exception Level: %d\r\n", current_EL());

	while (1) {
		volatile int i = 0;
		while (i < 1000000) {
			i++;
		}
		console_write(".");
	}
}

int current_EL() {
	int register_value;
	asm ("mrs %0, CurrentEL" : "=r" (register_value));
	register_value = register_value >> 2;
	return register_value;
}