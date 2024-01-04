#include <stdint.h>
#include "utils.h"
#include "memory_map/interrupt_controller.h"
#include "HAL/system_timer.h"
#include "exception_handler.h"
#include "console.h"

uint32_t* irq_source_registers[] = {IRQ_SOURCE0, IRQ_SOURCE1, IRQ_SOURCE2, IRQ_SOURCE3};
uint32_t* irq_pending0_registers[] = {IRQ0_PENDING0, IRQ1_PENDING0, IRQ2_PENDING0, IRQ3_PENDING0};
uint32_t* irq_pending1_registers[] = {IRQ0_PENDING1, IRQ1_PENDING1, IRQ2_PENDING1, IRQ3_PENDING1};
uint32_t* irq_pending2_registers[] = {IRQ0_PENDING2, IRQ1_PENDING2, IRQ2_PENDING2, IRQ3_PENDING2};

void (*irq_source_handlers[32]) ();
void (*irq_pending0_handlers[32]) ();
void (*irq_pending1_handlers[32]) ();
void (*irq_pending2_handlers[32]) ();

void unsupported_irq_handler();
void core_irq_handler();
void lower_VC_peripheral_irq_handler();
void upper_VC_peripheral_irq_handler();

void exception_handler_init() {
	for (int i = 0; i < 32; i++) {
		irq_source_handlers[i] = unsupported_irq_handler;
		irq_pending2_handlers[i] = unsupported_irq_handler;
		irq_pending2_handlers[i] = unsupported_irq_handler;
		irq_pending0_handlers[i] = unsupported_irq_handler;
	}
	irq_source_handlers[8] = core_irq_handler;
	irq_pending2_handlers[24] = lower_VC_peripheral_irq_handler;
	irq_pending2_handlers[25] = upper_VC_peripheral_irq_handler;
	// Attach system timer interrupt handlers
	irq_pending0_handlers[1] = handle_system_timer1_irq;	
}

void handle_irq_el1t() {
	uint32_t* irq_source_register = irq_source_registers[cpu_id()];
	uint32_t irq_source = READ_REG_32(irq_source_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_source & mask) {
			(*irq_source_handlers[i])();
		}
		mask = mask << 1;
	}
}

void core_irq_handler() {
	uint32_t* irq_pending2_register = irq_pending2_registers[cpu_id()];
	uint32_t irq_pending2 = READ_REG_32(irq_pending2_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_pending2 & mask) {
			(*irq_pending2_handlers[i])();
		}
		mask = mask << 1;
	}
}

void lower_VC_peripheral_irq_handler() {
	uint32_t* irq_pending0_register = irq_pending0_registers[cpu_id()];
	uint32_t irq_pending0 = READ_REG_32(irq_pending0_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_pending0 & mask) {
			(*irq_pending0_handlers[i])();
		}
		mask = mask << 1;
	}
}

void upper_VC_peripheral_irq_handler() {
	uint32_t* irq_pending1_register = irq_pending1_registers[cpu_id()];
	uint32_t irq_pending1 = READ_REG_32(irq_pending1_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_pending1 & mask) {
			(*irq_pending1_handlers[i])();
		}
		mask = mask << 1;
	}
}

void unsupported_irq_handler() {
	printf("Unsupported IRQ CPU ID: %d SRC: %x P2: %x P1: %x P0: %x\r\n",
			cpu_id(),
			READ_REG_32(irq_source_registers[cpu_id()]),
			READ_REG_32(irq_pending2_registers[cpu_id()]),
			READ_REG_32(irq_pending1_registers[cpu_id()]),
			READ_REG_32(irq_pending0_registers[cpu_id()]));
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
