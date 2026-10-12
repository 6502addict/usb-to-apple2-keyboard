#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "kbd.h"
#include "kbdconf.h"

#if KBD_OUTPUT == PARALLEL_A2

// DATA pins: Apple II D0-D6 → Pico GP (outputs)
//static const uint8_t data_pins[7] = {  4,  3,  1,  2,  7,  6,  0 };
//                                    D0  D1  D2  D3  D4  D5  D6
static const uint8_t data_pins[7] = {  4,  3, 28,  2,  7,  6,  29 };
//                                     D0  D1  D2  D3  D4  D5  D6

void kbd_init(void) {
    for (int i = 0; i < 7; i++) {
        gpio_init(data_pins[i]);
        gpio_set_dir(data_pins[i], GPIO_OUT);
        gpio_put(data_pins[i], 0);
    }
    // STROBE: output to Apple II (pulse to signal key ready)
    gpio_init(A2_STROBE_PIN);
    gpio_set_dir(A2_STROBE_PIN, GPIO_OUT);
    gpio_put(A2_STROBE_PIN, 0); // idle low

    // RESET: output to Apple II
    gpio_init(A2_RESET_PIN);
    gpio_set_dir(A2_RESET_PIN, GPIO_OUT);
    gpio_put(A2_RESET_PIN, 1); // idle high
}

void kbd_send(uint8_t ch) {
    // put 7-bit ASCII on DATA pins
    for (int i = 0; i < 7; i++)
        gpio_put(data_pins[i], (ch >> i) & 1);

    // pulse STROBE to signal key ready to Apple II (NE555 ~20ms)
    gpio_put(A2_STROBE_PIN, 1);
    sleep_ms(A2_STROBE_PULSE_MS);
    gpio_put(A2_STROBE_PIN, 0);

    // clear data lines
    //    for (int i = 0; i < 7; i++)
    //    gpio_put(data_pins[i], 0);
}

void kbd_reset(void) {
    gpio_put(A2_RESET_PIN, 0);
    sleep_ms(A2_RESET_PULSE_MS);
    gpio_put(A2_RESET_PIN, 1);
}

#endif
