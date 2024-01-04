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
1. IRQ
1. FIQ
1. System Error

### Vector Table
When taking an exception, the CPU will stop its normal line of execution and jump to the appropiate exception handler routine. The handlers are stored in the Vector Table. The Vector Table must be 2048 bytes aligned, with each entry being 128 bytes aligned.

### Handling IRQ
The handler must determine the source of the IRQ, then call the specific IRQ handler. The IRQ handler is implemented in `src/exception_handler.c`.

The `include/exception_handler.h` file defines the possible IRQ sources in the system. This is done to decouple the interrupt controller from the IRQ handling, meaning the `get_irq_source()` function in the interrupt controller just needs to return a defined IRQ source and the specific IRQ handler is called.

## Interrupt Controller
The BCM2711 chip contains 2 interrupt controllers, the Generic Interrupt Controller and the Legacy Interrupt Controller. This project utilizes the Legacy Interrupt Controller. 
The memory addresses are defined in `include/memory_map/interrupt_controller.h`, following Table 104 and Table 117 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf). 

The masking within the "ARMC routing" block is controlled by the SET_EN_0, SET_EN_1, SET_EN_2, CLR_EN_0, CLR_EN_1 and CLR_EN_2 registers. Each of these registers is repeated for each of the eight FIQn/IRQn signals (48 registers in total).

Once the interrupts have been masked and routed, their statuses can be read from the 3 PENDING and 1 SOURCE registers (repeated 8 times for each of the FIQn/IRQn signals, for a total of 32 registers).

These are "nested" status registers, which means if bit 8 in the SOURCE register is set, you also need to read PENDING2 to see which bits are set there. If bit 24 in the PENDING2 register is set, then you also need to read PENDING0 to see which
bits there are set.

The `interrupt_controller_init()` function enables the appropriate interrupts, then initializes the mapping of bit position in status registers to IRQ sources defined in `include/exception_handler.h`.

The `get_irq_source()` function is implemented to determine the source of the IRQ by traversing the "nested" structure of the status registers. If a bit is set in a status register, it is mapped to an IRQ source and returned to the IRQ handler for further processing.

## System Timer
The BCM2711 chip contains a system timer peripheral at memory addresses defined in `include/memory_map/system_timer.h`, following Table 166 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf). 

The system timer is a single 64-bit free running counter, split into higher and lower 32 bits to be read from `CHI` and `CLO` respectively. The system timer has four channels, each with its compare register `C0` to `C3`. An interrupt signal is generated on a specific channel when the lower 32 bits of the counter matches the value in the channel's compare register. The corresponding match detect status bit in the `CS` register is set as well. Writing 1 to the corresponding bit in the `CS` register will clear the match detect status bit and the corresponding interrupt request line.
