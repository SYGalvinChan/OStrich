#ifndef MINI_UART_H
#define MINI_UART_H

void mini_uart_init();
void mini_uart_tx(char c);
char mini_uart_rx();

// For printf
void putc ( void* p, char c);

#endif // MINI_UART_H
