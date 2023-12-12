#ifndef UTILS_H
#define UTILS_H

#define READ_REG_32(addr) (*(volatile unsigned int*) (addr))
#define WRITE_REG_32(addr, val) (*(volatile unsigned int*) (addr) = (val))

#endif // UTILS_H
