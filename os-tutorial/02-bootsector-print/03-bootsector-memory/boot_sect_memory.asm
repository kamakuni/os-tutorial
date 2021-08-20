mov ah, 0x0e

; attempt 1
; Fails because it tried to print the memory address (i.e printer)
; not its actual contents
mov al, "1"
int 0x10
mov al, the_secret
int 0x10
