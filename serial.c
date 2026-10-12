#include <stdio.h>
#include "pico/stdlib.h"
#include <stdlib.h>
#include <string.h>
#include "hardware/timer.h"
#include "hardware/uart.h"
#include "bsp/board.h"
#include "tusb.h"
#include "kbd_ringbuffer.h"
#include "kbd.h"
#include "kbdconf.h"

#if KBD_OUTPUT == SERIAL

void kbd_init(void) {
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_init(UART_ID, UART_BAUD);
    uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
}

void kbd_send(uint8_t ch) {
    uart_write_blocking(UART_ID, &ch, 1);
}

void kbd_reset(void) {
  // nothing for the moment
}


#endif
