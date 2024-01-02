#include "console.h"
#include "HAL/interupt_controller.h"
#include "HAL/system_timer.h"
#include <stdint.h>
#include "exception_handler.h"

void irq_init_vectors();
void irq_enable();
void irq_disable();

char cpu_stacks[4 * 4096];
int started = 0;

int cpu_id();

void main(void) {
	if (cpu_id() == 0) {
		console_init();
		printf("Console initialized!!!!\r\n");

		// irq_init_vectors();
		// system_timer_init();	
		// interupt_controller_init();	
		// exception_handler_init();
		// irq_enable();
		started = 1;
	}
	
	while (started == 0) ;
	while (1) {
		volatile int i = 0;
		while (i < 1000000) {
			i++;
		}
		printf("CPU ID: %d - ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n", cpu_id());
	}
}

int cpu_id() {
	uint32_t register_value;
	asm ("mrs %0, mpidr_el1" : "=r" (register_value));
	return register_value & 3;
}