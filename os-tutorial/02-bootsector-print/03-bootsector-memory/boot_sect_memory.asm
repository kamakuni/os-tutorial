mov ah, 0x0e

; attempt 1
; Fails because it tried to print the memory address (i.e printer)
; not its actual contents
mov al, "1"
int 0x10
mov al, the_secret
int 0x10

; attempt 2¥
; It tries to print the memory address of 'the_secret' which is the correct approach.
; However, BIOS places our bootsector binary at address 0x7c00
; so we need to add that padding beforehand. We'll do that in attempt 3
mov al, "2"
int 0x10
mov al, [the_secret]
int 0x10