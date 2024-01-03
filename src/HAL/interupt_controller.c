#include "HAL/interupt_controller.h"
#include "memory_map/interupt_controller.h"
#include "utils.h"
#include <stdint.h>

void interupt_controller_init() {
    WRITE_REG_32(IRQ0_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ1_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ2_SET_EN_0, 0x02);
    WRITE_REG_32(IRQ3_SET_EN_0, 0x02);
}
 