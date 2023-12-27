#include <stdint.h>
#include "utils.h"
#include "memory_map/interupt_controller.h"
#include "printf.h"
#include "system_timer.h"

void handle_irq() {
	uint32_t top_level_status_register = READ_REG_32(IRQ_SOURCE0);
	uint32_t second_level_status_register = READ_REG_32(IRQ0_PENDING2);
	uint32_t third_level_status_register = READ_REG_32(IRQ0_PENDING0);
	if ((top_level_status_register & 0x100) 
			&& (second_level_status_register & 1 << 24)
			&& (third_level_status_register & 2)) {
		handle_system_timer_irq(SYSTEM_TIMER_1);
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
