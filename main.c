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

bool debug = false;
bool hid_debug = false;
KbdRingBuffer *krb = NULL;
uint8_t lang = KBD_LANG;
uint8_t term = KBD_TERM;


void kbd_init(void);
void kbd_send(uint8_t);

int  kbd_decode_apple2(KbdRingBuffer *, uint8_t, uint8_t);

void  dump(uint8_t *buffer, size_t size) {
  uint32_t i, a, lsize;
  int c;

  for (a = 0;;) {
    printf("%08X: ", a);
    lsize = (size >= 16) ? 16 : size;
    for (i=0 ; i<lsize; i++)
      printf("%02X ", buffer[a + i]);
    for (i = lsize; i<16; i++)
      printf("   ");
    printf("  |");
    for (i=0;i<lsize;i++) {
      c = buffer[a+i];
      printf("%c", ((c < 0x20) || (c > 126)) ? '.' : c);
    }
    for (i=size;i<32;i++)
      printf(" ");
    a += lsize;
    size -= lsize;
    printf("|\n");
    if (size <= 0)
      return;
  }
}


void process_keycode(int keycode, int modifier) {
  if (debug)
    printf("keycode: %04x, modified %04x\n", keycode, modifier);
  switch (term) {
  case TERM_APPLE2:
    kbd_decode_apple2(krb, keycode, modifier);
    break;
  }
}

bool led_service(repeating_timer_t *rt) {
  static bool led_state = false;
  board_led_write(led_state);
  led_state = !led_state;
  return true;
}

int main(void) {
  static struct repeating_timer timer_led;
  

  board_init();
  kbd_init();
  krb = KbdRingBufferCreate();
  tusb_init();
  add_repeating_timer_ms(500, led_service, NULL, &timer_led);
  while (1) {
    uint16_t key;
    
    tuh_task();
    while (KbdGetKey(krb, &key)) {
      uint8_t ch;

      ch = key & 0xff;
      kbd_send(ch);
    }
  }
  KbdRingBufferRelease(krb);
}
