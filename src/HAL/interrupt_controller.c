#include "HAL/interrupt_controller.h"
#include "memory_map/interrupt_controller.h"
#include "utils.h"
#include <stdint.h>

void interrupt_controller_init() {
    // Enable System Timer 1 interrupt for all 4 cores
    WRITE_REG_32(IRQ0_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ1_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ2_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ3_SET_EN_0, 0x02);
}
 