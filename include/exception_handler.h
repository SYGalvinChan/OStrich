#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

void exception_handler_init();
void attach_exception_handler(int handler_type, int position, void (*handler) (void));
void core_irq_handler();
void lower_VC_peripheral_irq_handler();
void upper_VC_peripheral_irq_handler();
#endif // EXCEPTION_HANDLER_H