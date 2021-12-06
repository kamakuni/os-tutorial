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
        case 0x5:
            kprint("4");
            break;
        case 0x6:
            kprint("5");
            break;
        case 0x7:
            kprint("6");
            break;
        case 0x8:
            kprint("7");
            break;
        case 0x9:
            kprint("8");
            break;
        case 0x0A:
            kprint("9");
            break;
        case 0x0B:
            kprint("0");
            break;
        case 0x0C:
            kprint("-");
            break;
        case 0x0D:
            kprint("+");
            break;
        case 0x0E:
            kprint("Backspace");
            break;
        case 0x0F:
            kprint("Tab");
            break;
        case 0x10:
            kprint("Q");
            break;
        case 0x11:
            kprint("W");
            break;
        case 0x12:
            kprint("E");
            break;
        case 0x13:
            kprint("R");
            break;
        case 0x14:
            kprint("T");
            break;
        case 0x15:
            kprint("Y");
            break;
        case 0x16:
            kprint("U");
            break;
        case 0x17:
            kprint("I");
            break;
        case 0x18:
            kprint("O");
            break;
        case 0x19:
            kprint("P");
            break;
        default:
            break;
    }
}
