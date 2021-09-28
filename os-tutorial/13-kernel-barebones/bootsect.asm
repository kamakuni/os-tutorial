[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; The same one we used when linking the kernel

    mov [BOOT_DRIVE], dl ; Remember that the BIOS sets us the boot drive in 'dl on boot
    mov bp, 0x9000
    mov sp, bp

    mov bx, MSG_REAL_MODE
    call print
    call print_nl

    call load_kernel ; read the kernel from disk
    call switch_to_pm ; disable interrupts, load GDT, etc. Finally jumps to 'BEGIN_PM'
    jmp $ ; Never executed

%include "../05-bootsector-functions-strings/boot_sect_print.asm"
%include "../05-bootsector-functions-strings/boot_sect_print_hex.asm"
%include "../07-bootsector-disk/boot_sect_disk.asm"
%include "../09-32bit-gdt/32bit-gdt.asm"
%include "../08-32bit-print/32bit-print.asm"
%include "../10-32bit-enter/32bit-switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; Read from disk and store in 0x1000
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

