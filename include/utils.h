#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define READ_REG_32(addr) (*(volatile uint32_t*) (addr))
#define WRITE_REG_32(addr, val) (*(volatile uint32_t*) (addr) = (val))

int cpu_id();
void irq_enable();
void irq_disable();
int is_irq_enabled();
void delay(int cycles);

#endif // UTILS_H
