#ifndef CONSOLE_H
#define CONSOLE_H

#include "mini_uart.h"

void console_init();
void console_write(char* str);
char* console_readline();

#endif // CONSOLE_H
