#include "HAL/interupt_controller.h"
#include "memory_map/interupt_controller.h"
#include "utils.h"
#include "printf.h"
#include <stdint.h>

void interupt_controller_init() {
    // Enable timer 0 - 3 interupts
    WRITE_REG_32(IRQ0_SET_EN_0, 0x0F);
}
 