#include "keyboard.h"
#include "ports.h"
#include "../cpu/isr.h"
#include "screen.h"

static void keyboard_callback(register_t regs) {
    /* The PIC leaves us the scancode in port 0x60 */
    u8 scancode = port_byte_in(0x60);
    char *sc_ascii;
    int_to_ascii(scancode, sc_ascii);
    kprint("Keyboard scancode: ");
    kprint(sc_ascii);
    kprint(", ");
    print_letter(scancode);
    kprint("\n");
}

void init_keyboard(u8 scancode) {
    register_interrupt_handler(IRQ1, keyboard_callback);
}

void print_letter(u8 scancode) {
    switch (scancode) {
        case 0x0:
            kprint("ERROR");
            break;
        case 0x1:
            kprint("ESC");
            break;
        case 0x2:
            kprint("1");
            break;
        case 0x3:
            kprint("2");
            break;
        case 0x4:
            kprint("3");
            break;
        default:
            break;
    }
}
