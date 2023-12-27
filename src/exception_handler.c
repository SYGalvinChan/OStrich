#include <stdint.h>
#include "utils.h"
#include "memory_map/interupt_controller.h"
#include "printf.h"
#include "HAL/system_timer.h"
#include "exception_handler.h"

void (*irq_pending2_handlers[32]) ();
void (*irq_pending1_handlers[32]) ();
void (*irq_pending0_handlers[32]) ();
void (*irq_source_handlers[32]) ();


void exception_handler_init() {
	irq_source_handlers[8] = core_irq_handler;
	irq_pending2_handlers[24] = lower_VC_peripheral_irq_handler;
	irq_pending2_handlers[25] = upper_VC_peripheral_irq_handler;
	irq_pending0_handlers[1] = handle_system_timer_irq;
}

void handle_irq() {
	uint32_t irq_source = READ_REG_32(IRQ_SOURCE0);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_source & mask) {
			(*irq_source_handlers[i])();
		}
		mask = mask << 1;
	}
}

void core_irq_handler() {
	uint32_t irq_source = READ_REG_32(IRQ0_PENDING2);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_source & mask) {
			(*irq_pending2_handlers[i])();
		}
		mask = mask << 1;
	}
}

void lower_VC_peripheral_irq_handler() {
	uint32_t irq_source = READ_REG_32(IRQ0_PENDING0);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_source & mask) {
			(*irq_pending0_handlers[i])();
		}
		mask = mask << 1;
	}
}

void upper_VC_peripheral_irq_handler() {
	uint32_t irq_source = READ_REG_32(IRQ0_PENDING1);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_source & mask) {
			(*irq_pending1_handlers[i])();
		}
		mask = mask << 1;
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
