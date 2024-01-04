#include "console.h"
#include "HAL/interrupt_controller.h"
#include "HAL/system_timer.h"
#include "utils.h"
#include <stdint.h>
#include "exception_handler.h"

void irq_init_vectors();

char cpu_stacks[4 * 4096];
int started = 0;

void main(void) {
	if (cpu_id() == 0) {
		console_init();
		printf("Console initialized!!!!\r\n");

		system_timer_init();
		interrupt_controller_init();
		exception_handler_init();

		started = 1;
	}
	
	while (started == 0) ;
	irq_init_vectors();
	irq_enable();
	while (1) {
		delay(0x200000);
		printf("CPU ID: %d ...\r\n", cpu_id());
	}
}

int cpu_id() {
	uint32_t register_value;
	asm ("mrs %0, mpidr_el1" : "=r" (register_value));
	return register_value & 3;
}

int is_irq_enabled() {
	uint32_t register_value;
	asm ("mrs %0, DAIF" : "=r" (register_value));
	return !(register_value & 0x80);
}

void delay(int cycles) {
	volatile int tmp = 0;
	while (tmp < cycles) {
		tmp++;
	}
}