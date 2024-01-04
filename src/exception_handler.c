#include <stdint.h>
#include "utils.h"
#include "HAL/system_timer.h"
#include "exception_handler.h"
#include "console.h"
#include "HAL/interrupt_controller.h"

void (*irq_handlers[MAX_IRQ]) ();

void exception_handler_init() {
	interrupt_controller_init();
	// Attach system timer interrupt handlers
	irq_handlers[IRQ_SRC_SYSTEM_TIMER_1] = handle_system_timer1_irq;	
}

void handle_irq_el1t() {
	int irq_src = get_irq_src(cpu_id());
	switch (irq_src)
	{
		case IRQ_SRC_NOT_FOUND:
			/* code */
			break;
		case IRQ_SRC_UNSUPPORTED_IRQ:
			/* code */
			break;
		default:
			irq_handlers[irq_src]();
			break;
	}
}

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}
