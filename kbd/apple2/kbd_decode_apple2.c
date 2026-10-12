#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "bsp/board.h"
#include "tusb.h"
#include "kbd_ringbuffer.h"
#include "kbd.h"
#include "kbd_map.h"

void kbd_reset(void);

// language map pointer table — order must match LANG_EN/LANG_FR/LANG_ES/LANG_DE
static const int (*to_ascii[])[4] = {
    kbd_map_apple2_en,
    kbd_map_apple2_fr
};

// Apple II special keys — single byte only, no escape sequences
static uint8_t *special[] = {
    "\r",    "\r",    "\r",    "\r",    // KEY_ENTER  0x8000
    "",      "",      "",      "",      // KEY_UP     0x8001  unused
    "",      "",      "",      "",      // KEY_DOWN   0x8002  unused
    "\x15",  "\x15",  "\x15",  "\x15",  // KEY_RIGHT  0x8003  ctrl-U
    "\x08",  "\x08",  "\x08",  "\x08",  // KEY_LEFT   0x8004  ctrl-H
    "",      "",      "",      "",      // KEY_INSERT 0x8005  unused
    "\x7F",  "\x7F",  "\x7F",  "\x7F",  // KEY_DELETE 0x8006  rubout
    "",      "",      "",      "",      // KEY_PGUP   0x8007  unused
    "",      "",      "",      "",      // KEY_PGDN   0x8008  unused
    "",      "",      "",      "",      // KEY_HOME   0x8009  unused
    "",      "",      "",      "",      // KEY_END    0x800A  unused
    "",      "",      "",      "",      // KEY_PAUSE  0x800B  unused
    "",      "",      "",      "",      // KEY_F1     0x800C  unused
    "",      "",      "",      "",      // KEY_F2     0x800D  unused
    "",      "",      "",      "",      // KEY_F3     0x800E  unused
    "",      "",      "",      "",      // KEY_F4     0x800F  unused
    "",      "",      "",      "",      // KEY_F5     0x8010  unused
    "",      "",      "",      "",      // KEY_F6     0x8011  unused
    "",      "",      "",      "",      // KEY_F7     0x8012  unused
    "",      "",      "",      "",      // KEY_F8     0x8013  unused
    "",      "",      "",      "",      // KEY_F9     0x8014  unused
    "",      "",      "",      "",      // KEY_F10    0x8015  unused
    "",      "",      "",      "",      // KEY_F11    0x8016  unused
    "",      "",      "",      "",      // KEY_F12    0x8017  unused
};

static void enqueue(KbdRingBuffer *krb, uint16_t key, uint8_t mod) {
    uint8_t i, l;
    uint8_t *str;

    if ((key & 0x8000) == 0x8000) {
        uint8_t index = (key & 0xFF) << 2;
        if ((mod & KBD_MOD_CTRL)  == KBD_MOD_CTRL)  index |= 0x02;
        if ((mod & KBD_MOD_SHIFT) == KBD_MOD_SHIFT) index |= 0x01;
        str = special[index];
        for (i = 0, l = strlen(str); i < l; i++)
            KbdAddKey(krb, (uint8_t)str[i]);
    } else if (key <= 0xFF)
        KbdAddKey(krb, (uint8_t)key);
}

int kbd_decode_apple2(KbdRingBuffer *krb, uint8_t keycode, uint8_t modifier) {
    uint8_t  mod  = (modifier & 0x0F) | ((modifier >> 4) & 0x0F);
    uint16_t flag, key, skey, akey;

    // CTRL+ALT+DEL → reset
    if ((keycode == KBD_KEY_DELETE) && (modifier == (KBD_MOD_ALT | KBD_MOD_CTRL))) 
      kbd_reset();

    if ((modifier & KBD_MOD_WINDOW) == KBD_MOD_WINDOW) {
        switch (keycode) {
        case KBD_KEY_F1:  lang = LANG_EN; break;
        case KBD_KEY_F2:  lang = LANG_FR; break;
        case KBD_KEY_F12: debug = !debug; break;
        }
        return 0;
    }

    flag = to_ascii[lang][keycode][0];
    key  = to_ascii[lang][keycode][1];
    skey = to_ascii[lang][keycode][2];
    akey = to_ascii[lang][keycode][3];

    if ((mod & KBD_MOD_CTRL) == KBD_MOD_CTRL) {
      if ((key & 0x8000) == 0x8000)
        enqueue(krb, key, mod);
      else if ((flag & MOD_CTRL) == MOD_CTRL)
        KbdAddKey(krb, key & 0x1F);
      else if (akey != 0)
        KbdAddKey(krb, akey);
    } else if ((mod & KBD_MOD_ALT) == KBD_MOD_ALT) {
      if (akey != 0)
        KbdAddKey(krb, akey);
    } else {
      if (capslock_state || numlock_state)
        enqueue(krb, ((mod & KBD_MOD_SHIFT) == KBD_MOD_SHIFT) ? key : skey, mod);
      else
        enqueue(krb, ((mod & KBD_MOD_SHIFT) == KBD_MOD_SHIFT) ? skey : key, mod);
    }
    
    return 0;
}

