SECTIONS
{
	.text.boot : { *(.text.boot) }
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	. = ALIGN(8);
	bss_begin = .;
	.bss : { *(.bss*) }
	. = ALIGN(8); 
	bss_end = .;
	.stack :
	{
		. = ALIGN(16);
		stack_start = .;
		. = . + 4096;
		stack_end = .;
	}
    /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) }
}