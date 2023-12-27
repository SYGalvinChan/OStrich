#ifndef MM_SYSTEM_TIMER_H
#define MM_SYSTEM_TIMER_H

#define SYSTEM_TIMER_BASE_ADDRESS     (void *) 0xFE003000

#define CS   SYSTEM_TIMER_BASE_ADDRESS + 0x00 // System Timer Control/Status
#define CLO  SYSTEM_TIMER_BASE_ADDRESS + 0x04 // System Timer Counter Lower 32 bits
#define CHI  SYSTEM_TIMER_BASE_ADDRESS + 0x08 // System Timer Counter Higher 32 bits
#define C0   SYSTEM_TIMER_BASE_ADDRESS + 0x0c // System Timer Compare 0
#define C1   SYSTEM_TIMER_BASE_ADDRESS + 0x10 // System Timer Compare 1
#define C2   SYSTEM_TIMER_BASE_ADDRESS + 0x14 // System Timer Compare 2
#define C3   SYSTEM_TIMER_BASE_ADDRESS + 0x18 // System Timer Compare 3

#endif //MM_SYSTEM_TIMER_H
