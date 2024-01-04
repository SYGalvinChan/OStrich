# Multi Core and Exceptions
This release enables multi core, sets up the iterrupt controller and system timer in preparation for a scheduler.

## Using Multiple Cores
The Cortex-A72 processor in the Raspberry Pi has 4 cores. In order to make use of all the cores, the following line must be added to the `config.txt`:
```
kernel_old=1
```
The addition of that line also causes the firmware to load the kernel to the memory address `0x0000`. This has implications on the starting address of the stack. Previously, the stack starts right below the kernel code at address `0x80000`. For this release, `cpu_stacks` is a buffer declared in `main.c` to provide a stack space of 4Kb to each core. The stack pointer of each core is set to `cpu_stacks + (cpu_id + 1) * 4096`.

## Mutual Exclusion
With Multi Core enabled, protection of shared resources is essential to prevent multiple cores modifying the resource at the same time causing unexpected behaviors.

A spinlock mutex is implemented in `src/mutex.c` to ensure mutual exclusion. When a core wishes to use a shared resource, the core must first call `mutex_lock()`. The core waits in an infinite loop while the mutex is locked. When the mutex becomes unlocked, the core then locks the mutex to prevent another core from using the shared resource. After the core is done with the shared resource, the core then calls `mutex_unlock()` to unlock the mutex for another core.

## Exception Levels
There are four exception levels in AArch64, EL0 - EL3, with higher number indicating higher privilege. 
When the CPU is in a higher Exception Level, the CPU is able to execute more instructions and access more System Configuration Registors.

The only way to change exception levels is by taking an exception or returning from an exception.

## Exceptions
AArch64 specifies four types of exceptions:

1. Synchronous Exceptions
1. Interrupt
1. Fast Interrupt
1. System Error

### Vector Table
When taking an exception, the CPU will stop its normal line of execution and jump to the appropiate exception handler routine. The handlers are stored in the Vector Table. The Vector Table must be 2048 bytes aligned, with each entry being 128 bytes aligned.

## interrupt Controller
The BCM2711 chip contains 2 interrupt controllers, the Generic Interrupt Controller and the Legacy Interrupt Controller. This project utilizes the Legacy Interrupt Controller. 

## System Timer
The BCM2711 chip contains a system timer peripheral at memory addresses defined in `include/memory_map/system_timer.h`, following Table 166 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf). 

The system timer is a single 64-bit free running counter, split into higher and lower 32 bits to be read from `CHI` and `CLO` respectively. The system timer has four channels, each with its compare register `C0` to `C3`. An interrupt signal is generated on a specific channel when the lower 32 bits of the counter matches the value in the channel's compare register. The corresponding match detect status bit in the `CS` register is set as well. Writing 1 to the corresponding bit in the `CS` register will clear the match detect status bit and the corresponding interrupt request line.
