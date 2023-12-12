#ifndef MINI_UART_H
#define MINI_UART_H

#include "memory_map.h"

void mini_uart_init();
void mini_uart_tx(char c);
char mini_uart_rx();

#endif // MINI_UART_H
