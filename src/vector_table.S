#define S_FRAME_SIZE			256 

.globl el1_vector_table_init
el1_vector_table_init:
    adr    x0, el1_vector_table
    msr    vbar_el1, x0
    ret

.globl enable_irq
enable_irq:
    msr    daifclr, #2
    ret

.globl disable_irq
disable_irq:
    msr    daifset, #2
    ret

.macro    vector_table_entry    label
.align    7
    b    \label
.endm

.macro	kernel_entry
	sub	sp, sp, #S_FRAME_SIZE
	stp	x0, x1, [sp, #16 * 0]
	stp	x2, x3, [sp, #16 * 1]
	stp	x4, x5, [sp, #16 * 2]
	stp	x6, x7, [sp, #16 * 3]
	stp	x8, x9, [sp, #16 * 4]
	stp	x10, x11, [sp, #16 * 5]
	stp	x12, x13, [sp, #16 * 6]
	stp	x14, x15, [sp, #16 * 7]
	stp	x16, x17, [sp, #16 * 8]
	stp	x18, x19, [sp, #16 * 9]
	stp	x20, x21, [sp, #16 * 10]
	stp	x22, x23, [sp, #16 * 11]
	stp	x24, x25, [sp, #16 * 12]
	stp	x26, x27, [sp, #16 * 13]
	stp	x28, x29, [sp, #16 * 14]
	str	x30, [sp, #16 * 15] 
.endm

.macro	kernel_exit
	ldp	x0, x1, [sp, #16 * 0]
	ldp	x2, x3, [sp, #16 * 1]
	ldp	x4, x5, [sp, #16 * 2]
	ldp	x6, x7, [sp, #16 * 3]
	ldp	x8, x9, [sp, #16 * 4]
	ldp	x10, x11, [sp, #16 * 5]
	ldp	x12, x13, [sp, #16 * 6]
	ldp	x14, x15, [sp, #16 * 7]
	ldp	x16, x17, [sp, #16 * 8]
	ldp	x18, x19, [sp, #16 * 9]
	ldp	x20, x21, [sp, #16 * 10]
	ldp	x22, x23, [sp, #16 * 11]
	ldp	x24, x25, [sp, #16 * 12]
	ldp	x26, x27, [sp, #16 * 13]
	ldp	x28, x29, [sp, #16 * 14]
	ldr	x30, [sp, #16 * 15] 
	add	sp, sp, #S_FRAME_SIZE		
	eret
.endm

/*
 * Exception vectors.
 */
.align	11
.globl el1_vector_table 
el1_vector_table:
    vector_table_entry sync_el1t			// Synchronous EL1t
	vector_table_entry irq_el1t			    // IRQ EL1t
	vector_table_entry fiq_el1t			    // FIQ EL1t
	vector_table_entry error_el1t			// Error EL1t

	vector_table_entry sync_el1h			// Synchronous EL1h
	vector_table_entry irq_el1h			    // IRQ EL1h
	vector_table_entry fiq_el1h			    // FIQ EL1h
	vector_table_entry error_el1h			// Error EL1h

	vector_table_entry sync_el0_64			// Synchronous 64-bit EL0
	vector_table_entry irq_el0_64			// IRQ 64-bit EL0
	vector_table_entry fiq_el0_64			// FIQ 64-bit EL0
	vector_table_entry error_el0_64			// Error 64-bit EL0

	vector_table_entry sync_el0_32			// Synchronous 32-bit EL0
	vector_table_entry irq_el0_32			// IRQ 32-bit EL0
	vector_table_entry fiq_el0_32			// FIQ 32-bit EL0
	vector_table_entry error_el0_32			// Error 32-bit EL0

sync_el1t:
    kernel_entry
    bl handle_sync_el1t
    kernel_exit
irq_el1t:
    kernel_entry
    bl handle_irq_el1t
    kernel_exit
fiq_el1t:
    kernel_entry
    bl handle_fiq_el1t
    kernel_exit
error_el1t:
    kernel_entry
    bl handle_error_el1t
    kernel_exit
sync_el1h:
    kernel_entry
    bl handle_sync_el1h
    kernel_exit
irq_el1h:
    kernel_entry
    bl handle_irq_el1h
    kernel_exit
fiq_el1h:
    kernel_entry
    bl handle_fiq_el1h
    kernel_exit
error_el1h:
    kernel_entry
    bl handle_error_el1h
    kernel_exit
sync_el0_64:
    kernel_entry
    bl handle_sync_el0_64
    kernel_exit
irq_el0_64:
    kernel_entry
    bl handle_irq_el0_64
    kernel_exit
fiq_el0_64:
    kernel_entry
    bl handle_fiq_el0_64
    kernel_exit
error_el0_64:
    kernel_entry
    bl handle_error_el0_64
    kernel_exit
sync_el0_32:
    kernel_entry
    bl handle_sync_el0_32
    kernel_exit
irq_el0_32:
    kernel_entry
    bl handle_irq_el0_32
    kernel_exit
fiq_el0_32:
    kernel_entry
    bl handle_fiq_el0_32
    kernel_exit
error_el0_32:
    kernel_entry
    bl handle_error_el0_32
    kernel_exit
