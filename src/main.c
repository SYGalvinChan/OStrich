#include "console.h"


void main(void) {

	console_init();
	console_write("HELLO WORLD!!!!\r\n");

	while (1) {
		console_write(console_readline());
	}
}
