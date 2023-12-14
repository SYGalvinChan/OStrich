.section ".text.boot"

.globl _start
_start:
	// Reads Core ID from a System register
	mrs	    x0, mpidr_el1		
	and	    x0, x0, #0x03		
	// Core 1 - 3 goes into infinite loop while Core 0 continues
	cbnz	x0, infinite_loop	
	// Clear memory region for .bss segment
	adr	    x0, bss_begin
	adr	    x1, bss_end
	sub	    x1, x1, x0
loop:	
	cbz     x1, exit_loop
	str     xzr, [x0], #8
	subs    x1, x1, #8
	b.gt loop
exit_loop:	
	// Initiallize stack pointer to a valid memory address
    adr     x1, stack_end
    mov     sp, x1
	// Jump to main() function in src/main.c
	bl	    main
infinite_loop: 
	b 	    infinite_loop
