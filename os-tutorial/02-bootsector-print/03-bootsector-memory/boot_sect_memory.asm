mov ah, 0x0e

mov al, "1"
int 0x10
mov al, the_secret
int 0x10
