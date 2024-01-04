#include "HAL/system_timer.h"
#include "memory_map/system_timer.h"
#include "console.h"
#include "utils.h"
#include <stdint.h>

void system_timer_init() {
    // Clear match status bit first
    WRITE_REG_32(CS, 0x0F);
    // Set compare register for timer 1
    uint32_t register_value = READ_REG_32(CLO);
    register_value += COUNTER_INTERVAL;
    WRITE_REG_32(C1, register_value);
}

void handle_system_timer1_irq() {
    if (cpu_id() == 0) {
        // Wait a bit before clearing to ensure all cores are interrupted
        delay(0x500);
        // Clear match status bit
        WRITE_REG_32(CS, 2);
        // Set compare register for timer 1
        uint32_t clo_register_value = READ_REG_32(CLO);
        clo_register_value += COUNTER_INTERVAL;
        WRITE_REG_32(C1, clo_register_value);  
    }
    printf("Timer 1 interrupted CPU ID:%d\r\n", cpu_id());
    delay(0x2000);
}