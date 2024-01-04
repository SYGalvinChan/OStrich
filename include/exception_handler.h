#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#define MAX_IRQ 4

#define IRQ_SRC_SYSTEM_TIMER_0 0
#define IRQ_SRC_SYSTEM_TIMER_1 1
#define IRQ_SRC_SYSTEM_TIMER_2 2
#define IRQ_SRC_SYSTEM_TIMER_3 3

#define IRQ_SRC_UNSUPPORTED_IRQ -1
#define IRQ_SRC_NOT_FOUND -2

void exception_handler_init();
void attach_exception_handler(int handler_type, int position, void (*handler) (void));

#endif // EXCEPTION_HANDLER_H