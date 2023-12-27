#include "HAL/system_timer.h"
#include "memory_map/system_timer.h"
#include "utils.h"
#include <stdint.h>
#include "printf.h"
uint32_t * compare_registers[] = {C0, C1, C2, C3};

void system_timer_init() {
    WRITE_REG_32(CS, 0x0F);
    uint32_t register_value = READ_REG_32(CLO);
    register_value += COUNTER_INTERVAL;
    WRITE_REG_32(C1, register_value);

}

void handle_system_timer_irq() {
    printf("handle_system_timer_irq() called\r\n");
    WRITE_REG_32(CS, 2);
    uint32_t * compare_register = compare_registers[1];
    uint32_t register_value = READ_REG_32(CLO);
    register_value += COUNTER_INTERVAL;
    WRITE_REG_32(compare_register, register_value);    
}