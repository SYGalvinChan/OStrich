#include "console.h"

void main(void) {
	console_init();
	console_write("HELLO WORLD!!!!\n");

	while (1) {
		console_write(console_readline());
	}
}
