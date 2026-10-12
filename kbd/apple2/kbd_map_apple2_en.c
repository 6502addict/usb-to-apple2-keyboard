#include <stdint.h>
#include <stdbool.h>
#include "kbd.h"
#include "kbd_map.h"

const int kbd_map_apple2_en[128][4] = {
    { 0,                    0,             0,           0 }, // 0x00
    { 0,                    0,             0,           0 }, // 0x01
    { 0,                    0,             0,           0 }, // 0x02
    { 0,                    0,             0,           0 }, // 0x03
    { CAPS_LOCK | MOD_CTRL, 'a',         'A',        0x01 }, // 0x04
    { CAPS_LOCK | MOD_CTRL, 'b',         'B',        0x02 }, // 0x05
    { CAPS_LOCK | MOD_CTRL, 'c',         'C',        0x03 }, // 0x06
    { CAPS_LOCK | MOD_CTRL, 'd',         'D',        0x04 }, // 0x07
    { CAPS_LOCK | MOD_CTRL, 'e',         'E',        0x05 }, // 0x08
    { CAPS_LOCK | MOD_CTRL, 'f',         'F',        0x06 }, // 0x09
    { CAPS_LOCK | MOD_CTRL, 'g',         'G',        0x07 }, // 0x0a
    { CAPS_LOCK | MOD_CTRL, 'h',         'H',        0x08 }, // 0x0b
    { CAPS_LOCK | MOD_CTRL, 'i',         'I',        0x09 }, // 0x0c
    { CAPS_LOCK | MOD_CTRL, 'j',         'J',        0x0A }, // 0x0d
    { CAPS_LOCK | MOD_CTRL, 'k',         'K',        0x0B }, // 0x0e
    { CAPS_LOCK | MOD_CTRL, 'l',         'L',        0x0C }, // 0x0f
    { CAPS_LOCK | MOD_CTRL, 'm',         'M',        0x0D }, // 0x10
    { CAPS_LOCK | MOD_CTRL, 'n',         'N',        0x0E }, // 0x11
    { CAPS_LOCK | MOD_CTRL, 'o',         'O',        0x0F }, // 0x12
    { CAPS_LOCK | MOD_CTRL, 'p',         'P',        0x10 }, // 0x13
    { CAPS_LOCK | MOD_CTRL, 'q',         'Q',        0x11 }, // 0x14
    { CAPS_LOCK | MOD_CTRL, 'r',         'R',        0x12 }, // 0x15
    { CAPS_LOCK | MOD_CTRL, 's',         'S',        0x13 }, // 0x16
    { CAPS_LOCK | MOD_CTRL, 't',         'T',        0x14 }, // 0x17
    { CAPS_LOCK | MOD_CTRL, 'u',         'U',        0x15 }, // 0x18
    { CAPS_LOCK | MOD_CTRL, 'v',         'V',        0x16 }, // 0x19
    { CAPS_LOCK | MOD_CTRL, 'w',         'W',        0x17 }, // 0x1a
    { CAPS_LOCK | MOD_CTRL, 'x',         'X',        0x18 }, // 0x1b
    { CAPS_LOCK | MOD_CTRL, 'y',         'Y',        0x19 }, // 0x1c
    { CAPS_LOCK | MOD_CTRL, 'z',         'Z',        0x1A }, // 0x1d
    { 0,                    '1',         '!',        0x00 }, // 0x1e
    { 0,                    '2',         '"',        0x00 }, // 0x1f
    { 0,                    '3',         '#',        0x00 }, // 0x20
    { 0,                    '4',         '$',        0x00 }, // 0x21
    { 0,                    '5',         '%',        0x00 }, // 0x22
    { 0,                    '6',         '&',        0x00 }, // 0x23
    { 0,                    '7',        '\'',        0x00 }, // 0x24
    { 0,                    '8',         '(',        0x00 }, // 0x25
    { 0,                    '9',         ')',        0x00 }, // 0x26
    { 0,                    '0',         '0',        0x00 }, // 0x27
    { 0,              KEY_ENTER,   KEY_ENTER,   KEY_ENTER }, // 0x28
    { 0,              ASCII_ESC,   ASCII_ESC,   ASCII_ESC }, // 0x29
    { 0,               ASCII_BS,    ASCII_BS,    ASCII_BS }, // 0x2a
    { 0,               ASCII_HT,    ASCII_HT,    ASCII_HT }, // 0x2b
    { 0,                    ' ',         ' ',        0x00 }, // 0x2c
    { 0,                    '-',         '=',        0x00 }, // 0x2d
    { 0,                    '@',         '`',        0x00 }, // 0x2e
    { 0,                    '[',         '[',        0x00 }, // 0x2f
    { 0,                    ']',         ']',        0x00 }, // 0x30
    { 0,                   '\\',        '\\',        0x00 }, // 0x31
    { 0,                    '#',         '~',        0x00 }, // 0x32
    { 0,                    ';',         '+',        0x00 }, // 0x33
    { 0,                    ':',         '*',        0x00 }, // 0x34
    { 0,                    '`',         '~',        0x00 }, // 0x35
    { 0,                    ',',         '<',        0x00 }, // 0x36
    { 0,                    '.',         '>',        0x00 }, // 0x37
    { 0,                    '/',         '?',        0x00 }, // 0x38
    { 0,            KEY_CAPSLCK, KEY_CAPSLCK, KEY_CAPSLCK }, // 0x39
    { 0,                      0,           0,           0 }, // 0x3a  F1  — unused
    { 0,                      0,           0,           0 }, // 0x3b  F2
    { 0,                      0,           0,           0 }, // 0x3c  F3
    { 0,                      0,           0,           0 }, // 0x3d  F4
    { 0,                      0,           0,           0 }, // 0x3e  F5
    { 0,                      0,           0,           0 }, // 0x3f  F6
    { 0,                      0,           0,           0 }, // 0x40  F7
    { 0,                      0,           0,           0 }, // 0x41  F8
    { 0,                      0,           0,           0 }, // 0x42  F9
    { 0,                      0,           0,           0 }, // 0x43  F10
    { 0,                      0,           0,           0 }, // 0x44  F11
    { 0,                      0,           0,           0 }, // 0x45  F12
    { 0,                      0,           0,           0 }, // 0x46  PRTSCR
    { 0,                      0,           0,           0 }, // 0x47  SCRLCK
    { 0,                      0,           0,           0 }, // 0x48  PAUSE
    { 0,                      0,           0,           0 }, // 0x49  INSERT
    { 0,                      0,           0,           0 }, // 0x4a  HOME
    { 0,                      0,           0,           0 }, // 0x4b  PGUP
    { 0,             KEY_DELETE,  KEY_DELETE,  KEY_DELETE }, // 0x4c  rubout
    { 0,                      0,           0,           0 }, // 0x4d  END
    { 0,                      0,           0,           0 }, // 0x4e  PGDN
    { 0,              KEY_RIGHT,   KEY_RIGHT,   KEY_RIGHT }, // 0x4f
    { 0,               KEY_LEFT,    KEY_LEFT,    KEY_LEFT }, // 0x50
    { 0,                      0,           0,           0 }, // 0x51  DOWN unused
    { 0,                      0,           0,           0 }, // 0x52  UP   unused
    { 0,                      0,           0,           0 }, // 0x53  NUMLCK
    { 0,                    '/',         '/',        0x00 }, // 0x54
    { 0,                    '*',         '*',        0x00 }, // 0x55
    { 0,                    '-',         '-',        0x00 }, // 0x56
    { 0,                    '+',         '+',        0x00 }, // 0x57
    { 0,              KEY_ENTER,   KEY_ENTER,   KEY_ENTER }, // 0x58
    { NUM_LOCK,             '1',           0,           0 }, // 0x59
    { NUM_LOCK,             '2',           0,           0 }, // 0x5a
    { NUM_LOCK,             '3',           0,           0 }, // 0x5b
    { NUM_LOCK,             '4',           0,           0 }, // 0x5c
    { NUM_LOCK,             '5',           0,           0 }, // 0x5d
    { NUM_LOCK,             '6',           0,           0 }, // 0x5e
    { NUM_LOCK,             '7',           0,           0 }, // 0x5f
    { NUM_LOCK,             '8',           0,           0 }, // 0x60
    { NUM_LOCK,             '9',           0,           0 }, // 0x61
    { NUM_LOCK,             '0',           0,           0 }, // 0x62
    { NUM_LOCK,             '.',           0,           0 }, // 0x63
    { NUM_LOCK,             '=',           0,           0 }, // 0x64
};
