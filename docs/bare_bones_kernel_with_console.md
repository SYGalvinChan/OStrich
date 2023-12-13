# Bare Bones Kernel with Console

## Overview
This release provides the implementation of a minimal Operating System targeting Raspberry Pi 4B with 4GB RAM.
The kernel has no capabilities, it simply reads input from the console and writes it back.
A basic console is implemented using mini UART to allow the Operating System to communicate with the dev machine for debugging and testing.

## Entry Point
The entry point of the kernel is `_start` found in `src/boot.S`. It has to be written in assembly language to setup the environment for execution of C code.
The steps are as follows:

1. Reads Core ID from a System register
1. Core 1 - 3 goes into infinite loop while Core 0 continues (Will change later to allow other cores to be used)
1. Clear memory region for `.bss` segment
1. Initiallize stack pointer to a valid memory address
1. Jump to `main()` function in `src/main.c` 

## Main Kernel
Since this is a bare bones kernel with console, the `main()` function simply initializes the console, writes `Hello World` to the console, then goes into infinite loop that reads a line from the console and writes it back.

## Console
The console is implemented using mini UART and provides basic abstraction. The console maintains a buffer to store characters received from mini UART.

`console_init()` initializes the mini UART.

`console_write()` takes in a null-terminated string, iterates over each character and calls `mini_uart_tx()` to transmit the character. 

`console_readline()` repeatedly calls `mini_uart_rx()`, storing the characters in the buffer until a new line character is received. The string is then terminated with the null character and returned to the caller.

## Mini Universal Asynchronous Receiver/Transmitter
The console is implemented using mini UART, which is one of the three Auxiliary peripherals. These AUX peripherals are memory mapped,  where a memory addresses are mapped to registers for controlling the peripherals. Reading and writing to these memory address will allow us to read and write to the mapped registers. The memory addresses are defined in `include/memory_map/aux.h`, following Table 2 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf). 

The mini UART is a secondary low throughput UART intended to be used as a console. It needs to be enabled before it can be used. It is also recommended that the correct GPIO function mode is selected before enabling the mini UART.

The following functions are found in `src/mini_uart.c`.

### Initializing the mini UART 
The initialization of the mini UART is done in `mini_uart_init()`.The steps are as follows:

1. Set GPIO Pin 14 and 15 to alternative function 5 for UART1 TXD/RXD
1. Set Pull Up/Pull Down resistor for GPIO Pin 14 and 15 to none
1. Enable mini UART
1. Disable extra controls, transmitter and receiver for now
1. Disable transmit and receive interupts 
1. Set data size to 8 bits and allow access to baudrate register
1. Set baudrate to 115200
1. Enable transmitter and receiver

### Input and Output with mini UART 
The mini UART features 8 symbols deep FIFOs for receive and transmit. Input and output with the mini UART is implemented in the `mini_uart_tx()` and `mini_uart_rx()` functions.

`mini_uart_tx()` takes in as argument a `char`, waits for the transmit FIFO to be able to accept a symbol, before putting the argument into the transmit FIFO.

`mini_uart_rx()` waits for the receive FIFO to hold at least one symbol before reading a symbol from the receive FIFO and returning a `char` to the caller.

## General Purpose Input/Output
As well as being able to be used as straightforward software controlled input and output (with programmable pulls), GPIO pins can be switched (multiplexed) into various other alternate functions backed by dedicated peripheral blocks such as I2C, UART and SPI.

The GPIO peripheral is also memory mapped. The memory addresses are defined in `include/memory_map/gpio.h`, following Table 63 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf).

The following functions are found in `src/gpio.c`.

### Alternate Functions
Each GPIO pin can set up to perform one of many functions (input, output, up to 6 alternate functions). Table 94 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf) shows the mapping of each pin to its alternative functions. 

`gpio_set_func()` can be used to set a specified GPIO pin to perform a specified function.

### Pull State

Pull-up and Pull-down resistors are used to correctly bias the GPIO pin to stop it from floating about randomly when there is no input condition. Intuitively, the pull state of a pin is the default output (HIGH or LOW) when nothing is being outputed on the pin. Each GPIO pin can be configured to be pulled up, pulled down, or no pull.

`gpio_set_pull_state()` can be used to set a specified GPIO pin to a specified pull state.