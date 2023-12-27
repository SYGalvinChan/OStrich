#include "console.h"
#include "printf.h"
#include "HAL/interupt_controller.h"
#include "HAL/system_timer.h"
#include <stdint.h>

void irq_init_vectors();
void irq_enable();
void irq_disable();

void main(void) {

	console_init();
	console_write("Console initialized!!!!\r\n");

	irq_init_vectors();
	system_timer_init();	
	interupt_controller_init();	
	irq_enable();

	while (1) {
		volatile int i = 0;
		while (i < 1000000) {
			i++;
		}
		printf(".");
	}
}
