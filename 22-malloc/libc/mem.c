#include "mem.h"

void memory_copy(u8 *source, u8 *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len) {
    u8 *temp = (u8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

/* This should be computed at link time, but a hardcoded
 * value is fine for now. Remember that out kernel starts
 * at 0x1000 as defined on the Makefile */
u32 free_mem_addr = 0x10000;
