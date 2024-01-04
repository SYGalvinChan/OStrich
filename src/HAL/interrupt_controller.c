#include "HAL/interrupt_controller.h"
#include "memory_map/interrupt_controller.h"
#include "utils.h"
#include <stdint.h>
#include "exception_handler.h"

// These arrays hold the address of interrupt controller registers for determining source of IRQ
uint32_t* irq_source_registers[] = {IRQ_SOURCE0, IRQ_SOURCE1, IRQ_SOURCE2, IRQ_SOURCE3};
uint32_t* irq_pending0_registers[] = {IRQ0_PENDING0, IRQ1_PENDING0, IRQ2_PENDING0, IRQ3_PENDING0};
uint32_t* irq_pending1_registers[] = {IRQ0_PENDING1, IRQ1_PENDING1, IRQ2_PENDING1, IRQ3_PENDING1};
uint32_t* irq_pending2_registers[] = {IRQ0_PENDING2, IRQ1_PENDING2, IRQ2_PENDING2, IRQ3_PENDING2};

// These arrays maps the bit position of above registers to irq srcs defined in exception_handler.h
int irq_source_bit_to_irq_src[32];
int irq_pending0_bit_to_irq_src[32];
int irq_pending1_bit_to_irq_src[32];
int irq_pending2_bit_to_irq_src[32];

int get_core_irq_src(int cpu_id);
int get_lower_VC_peripheral_irq_src(int cpu_id);
int get_upper_VC_peripheral_irq_src(int cpu_id);

void interrupt_controller_init() {
    // Enable System Timer 1 interrupt for all 4 cores
    WRITE_REG_32(IRQ0_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ1_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ2_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ3_SET_EN_0, 0x02);

	// Initialize mapping from bit position to irq src
	for (int i = 0; i < 32; i++) {
		irq_source_bit_to_irq_src[i] = IRQ_SRC_UNSUPPORTED_IRQ;
		irq_pending0_bit_to_irq_src[i] = IRQ_SRC_UNSUPPORTED_IRQ;
		irq_pending1_bit_to_irq_src[i] = IRQ_SRC_UNSUPPORTED_IRQ;
		irq_pending2_bit_to_irq_src[i] = IRQ_SRC_UNSUPPORTED_IRQ;
	}
	irq_pending0_bit_to_irq_src[0] = IRQ_SRC_SYSTEM_TIMER_0;
	irq_pending0_bit_to_irq_src[1] = IRQ_SRC_SYSTEM_TIMER_1;
	irq_pending0_bit_to_irq_src[2] = IRQ_SRC_SYSTEM_TIMER_2;
	irq_pending0_bit_to_irq_src[3] = IRQ_SRC_SYSTEM_TIMER_3;
}

int get_irq_src(int cpu_id) {
	uint32_t* irq_source_register = irq_source_registers[cpu_id];
	uint32_t irq_source = READ_REG_32(irq_source_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
        if ((irq_source & mask) && (i == 8)) {
			// if bit 8 is 1, need check irq pending2 register to find irq src
            return get_core_irq_src(cpu_id);
        } else if (irq_source & mask) {
			return irq_source_bit_to_irq_src[i];
		}
		mask = mask << 1;
	}
    return IRQ_SRC_NOT_FOUND;
}

int get_core_irq_src(int cpu_id) {
	uint32_t* irq_pending2_register = irq_pending2_registers[cpu_id];
	uint32_t irq_pending2 = READ_REG_32(irq_pending2_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
        if ((irq_pending2 & mask) && (i == 24)) {
			// if bit 24 is 1, need check irq pending0 register to find irq src
            return get_lower_VC_peripheral_irq_src(cpu_id);
        } else if ((irq_pending2 & mask) && (i == 25)) {
			// if bit 8 is 25, need check irq pending1 register to find irq src
            return get_upper_VC_peripheral_irq_src(cpu_id);
        } else if (irq_pending2 & mask) {
			return irq_pending2_bit_to_irq_src[i];
		}
		mask = mask << 1;
	}
    return IRQ_SRC_NOT_FOUND;
}

int get_lower_VC_peripheral_irq_src(int cpu_id) {
	uint32_t* irq_pending0_register = irq_pending0_registers[cpu_id];
	uint32_t irq_pending0 = READ_REG_32(irq_pending0_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_pending0 & mask) {
			return irq_pending0_bit_to_irq_src[i];
		}
		mask = mask << 1;
	}
    return IRQ_SRC_NOT_FOUND;
}

int get_upper_VC_peripheral_irq_src(int cpu_id) {
	uint32_t* irq_pending1_register = irq_pending1_registers[cpu_id];
	uint32_t irq_pending1 = READ_REG_32(irq_pending1_register);
	uint32_t mask = 1;
	for (int i = 0; i < 32; i++) {
		if (irq_pending1 & mask) {
			return irq_pending1_bit_to_irq_src[i];
		}
		mask = mask << 1;
	}
    return IRQ_SRC_NOT_FOUND;
}