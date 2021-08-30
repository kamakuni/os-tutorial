print:
    pusha

; keep this in mind:
; while (string[i] !+ 0) { print string[i]; i++ }

; the comparison for string end (null byte)
start:
    mov al, [bx]
    cmp al, 0
    je done
    