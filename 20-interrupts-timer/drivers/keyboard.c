#include "keyboard.h"
#include "ports.h"
#include "../cpu/isr.h"
#include "screen.h"

static void keyboard_callback(registers_t regs) {
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

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}

void print_letter(u8 scancode) {
    switch (scancode) {
        case 0x0:
            kprint("ERROR");
            break;
        default:
            if (scancode <= 0x7f) {
                kprint("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                kprint("Key up");
                print_letter(scancode - 0x80);
            } else kprint("Unknown key up");
            break;
    }
}