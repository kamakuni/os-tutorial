#include "timer.h"
#include "../drivers/screen.h"
#include "../kernel/util.h"
#include "isr.h"

u32 tick = 0;

static void timer_callback(register_t regs) {
    tick++;
    kprint("Tick: ");

    char tick_ascii[256];
    int_to_ascii(tick, tick_ascii);
    kprint(tick_ascii);
    kprint("\n");
}
