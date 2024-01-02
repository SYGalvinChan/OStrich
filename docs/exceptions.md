# Exceptions
This release sets up the iterrupt controller and system timer in preparation for a scheduler.
## Exception Levels
There are four exception levels in AArch64, EL0 - EL3, with higher number indicating higher privilige. 
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

## Interrupt Controller
The BCM2711 chip contains 2 interrupt controllers, the Generic Interrupt Controller and the Legacy Interrupt Controller. This project utilizes the Legacy Interrupt Controller. 

## System Timer
The BCM2711 chip contains a system timer peripheral at memory addresses defined in `include/memory_map/system_timer.h`, following Table 166 in the [datasheet](https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf). 

The system timer is a single 64-bit free running counter, split into higher and lower 32 bits to be read from `CHI` and `CLO` respectively. The system timer has four channels, each with its compare register `C0` to `C3`. An interrupt signal is generated on a specific channel when the lower 32 bits of the counter matches the value in the channel's compare register. The corresponding match detect status bit in the `CS` register is set as well. Writing 1 to the corresponding bit in the `CS` register will clear the match detect status bit and the corresponding interrupt request line.
