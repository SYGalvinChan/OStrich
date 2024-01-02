#ifndef CONSOLE_H
#define CONSOLE_H

void console_init();

#include <stdarg.h>

void init_printf(void* putp,void (*putf) (void*,char));

void printf(char *fmt, ...);
void sprintf(char* s,char *fmt, ...);

void tfp_format(void* putp,void (*putf) (void*,char),char *fmt, va_list va);

#endif // CONSOLE_H
