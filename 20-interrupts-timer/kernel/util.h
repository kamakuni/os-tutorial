#include "../cpu/types.h"

void memory_copy(char *source, char *dest, int nbytes);
void moery_set(u8 *dest, u8 val, u32 len);
void int_to_ascii(int n, char str[]);