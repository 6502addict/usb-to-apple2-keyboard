# usb-to-apple2-keyboard
adapter to connect a usb keyboard to an Apple II

This repository contains the code to process the usb keyboard scancodes and convert them into ascii

To build this converter you need the pico sdk installed.
(in my development I used the PICO XIAO RP2040 but the code can be adapted to any other pico)

To build the makefile type:  "cmake ."
To build the project type: "make"

To customize the output device check parallel_a2.c it's the pin mapping for my converter
You can derive this output program into many other things...
(for example I created a serial output to send data to a fpga board) 
It could also be modified to produce some custom output such as IR or PS/2

To customize the mapping check the kbd directory it contains a subdirectory for a specific machine here "apple2"
in this directory a series of files   (I use a raspberry pi keyboard for it's price and integrated usb hub)
kbd_decode_xxx.c    contains the coded to convert the USB scancodes into ASCII
kbd_map_xxx_en.c    contains the mapping table for an us english keyboard  
kbd_map_xxx_fr.c    contains the mapping table for a french keyboard  

some other langage can be added by adding for example:
kdb_map_xxx_es.c    for spanish
kdb_map_xxx_de.c    for german
....

if you define other language in kbd.h you need a #define by language
for example:
#define LANG_EN   0
#define LANG_FR   1
..
#define LANG_ES   2
#define LANG_DE   3

in kbd_map.h you need to define each new language mapping
#pragma once

// Each map is a 128x4 table: [keycode][0]=flags [1]=normal [2]=shift [3]=ctrl
extern const int kbd_map_apple2_en[128][4];
extern const int kbd_map_apple2_fr[128][4];
...
extern const int kbd_map_apple2_es[128][4];
extern const int kbd_map_apple2_fr[128][4];

in kbd_decode_apple2 you need to add extra mapping

static const int (*to_ascii[])[4] = {
    kbd_map_apple2_en,
    kbd_map_apple2_fr,
    kbd_map_apple2_es,
    kbd_map_apple2_de
};

if you want to switch the language with a key in kbd_decode_apple2.c you need to add new entries in the function kbd_decode_apple.


    if ((modifier & KBD_MOD_WINDOW) == KBD_MOD_WINDOW) {
        switch (keycode) {
        case KBD_KEY_F1:  lang = LANG_EN; break;
        case KBD_KEY_F2:  lang = LANG_FR; break;
        case KBD_KEY_F3:  lang = LANG_ES; break;
        case KBD_KEY_F4:  lang = LANG_DE; break;
        case KBD_KEY_F12: debug = !debug; break;
        }
        return 0;
    }


if you are more interested by matrix keyboard the code also works
I can send you my TRS80 keyboard for FPGA it's the same code but with a X/Y mapping and a serial interface

if you need this matrix code contact me at "didier"AT"aida.org"








