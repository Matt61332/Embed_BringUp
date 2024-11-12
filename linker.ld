MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM(rwx) : ORIGIN =  0x20000000, LENGTH = 4K
}

SECTIONS
{
    .stack (NOLOAD) : {
        . = ALIGN(4);
        . = . + 2K;
    } > RAM

    .text : {
        KEEP(*(.isr_vector))
        *(.reset_handler)
        *(.text)
        *(.data)
        *(.rodata)
        *(.bss)
    } > FLASH
}
