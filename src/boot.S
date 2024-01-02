#include "sysregs.h"
.extern cpu_stacks    // Found in main.c
.section ".text.boot"  // Make sure the linker puts this at the start of the kernel image

.global _start  // Execution starts here

_start:
    // Get CPU ID, only CPU ID 0 will clear BSS, rest jumps to all
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbnz     x1, all
    
    // Clean the BSS section
    ldr     x1, =__bss_start     // Start address
    ldr     w2, =__bss_size      // Size of the section
bss_loop:  
    cbz     w2, all               // Quit loop if zero
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, bss_loop               // Loop if non-zero

all:  // All cores go into EL1
	ldr	x0, =SCTLR_VALUE_MMU_DISABLED
	msr	sctlr_el1, x0		

	ldr	x0, =HCR_VALUE
	msr	hcr_el2, x0

	ldr	x0, =SCR_VALUE
	msr	scr_el3, x0

	ldr	x0, =SPSR_VALUE
	msr	spsr_el3, x0

	adr	x0, el1_entry		
	msr	elr_el3, x0

	eret			
el1_entry:

    // Set stack pointer = cpu_stacks + (cpu_id + 1) * 4096
    adr     x0, cpu_stacks
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    add     x1, x1, #1
    lsl     x1, x1, #12
    add     x1, x0, x1
    mov     sp, x1
    // Jump to our main() routine in C (make sure it doesn't return)
4:  bl      main
infinite_loop:
    b infinite_loop