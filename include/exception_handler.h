#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

void exception_handler_init();
void attach_exception_handler(int handler_type, int position, void (*handler) (void));

#endif // EXCEPTION_HANDLER_H