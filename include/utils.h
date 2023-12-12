#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define READ_REG_32(addr) (*(volatile uint32_t*) (addr))
#define WRITE_REG_32(addr, val) (*(volatile uint32_t*) (addr) = (val))

#endif // UTILS_H
