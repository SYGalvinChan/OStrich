#ifndef SYSTEM_TIMER_H
#define SYSTEM_TIMER_H

#define SYSTEM_TIMER_0 0
#define SYSTEM_TIMER_1 1
#define SYSTEM_TIMER_2 2
#define SYSTEM_TIMER_3 3

#define COUNTER_INTERVAL 0x200000

void system_timer_init();

void handle_system_timer1_irq();

#endif // SYSTEM_TIMER_H