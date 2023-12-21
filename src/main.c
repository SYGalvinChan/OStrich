#include "console.h"
#include "printf.h"

void main(void) {

	console_init();
	console_write("Console initialized!!!!\r\n");

	while (1) {
		volatile int i = 0;
		while (i < 1000000) {
			i++;
		}
		console_write(".");
	}
}
