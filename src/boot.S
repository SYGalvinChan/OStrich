.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		// Contains information about Core ID
	and	x0, x0, #0x03		// Mask to get first 2 bits
	cbnz	x0, infinite_loop	// Only Core 1 continues, rest hangs

	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
loop:	
	cbz     x1, exit_loop
	str     xzr, [x0], #8
	subs    x1, x1, #8
	b.gt loop
exit_loop:	
	// Set stack to start below our code
    ldr     x1, =_start
    mov     sp, x1
	bl	main
infinite_loop: 
	b 	infinite_loop
