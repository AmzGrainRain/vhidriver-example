#pragma once

#define VHID_KEY_MOD_LCTRL  0x01
#define VHID_KEY_MOD_LSHIFT 0x02
#define VHID_KEY_MOD_LALT   0x04
#define VHID_KEY_MOD_LMETA  0x08
#define VHID_KEY_MOD_RCTRL  0x10
#define VHID_KEY_MOD_RSHIFT 0x20
#define VHID_KEY_MOD_RALT   0x40
#define VHID_KEY_MOD_RMETA  0x80

#define VHID_KEY_NONE 0x00 // No key pressed

#define VHID_KEY_A 0x04 // Keyboard a and A
#define VHID_KEY_B 0x05 // Keyboard b and B
#define VHID_KEY_C 0x06 // Keyboard c and C
#define VHID_KEY_D 0x07 // Keyboard d and D
#define VHID_KEY_E 0x08 // Keyboard e and E
#define VHID_KEY_F 0x09 // Keyboard f and F
#define VHID_KEY_G 0x0a // Keyboard g and G
#define VHID_KEY_H 0x0b // Keyboard h and H
#define VHID_KEY_I 0x0c // Keyboard i and I
#define VHID_KEY_J 0x0d // Keyboard j and J
#define VHID_KEY_K 0x0e // Keyboard k and K
#define VHID_KEY_L 0x0f // Keyboard l and L
#define VHID_KEY_M 0x10 // Keyboard m and M
#define VHID_KEY_N 0x11 // Keyboard n and N
#define VHID_KEY_O 0x12 // Keyboard o and O
#define VHID_KEY_P 0x13 // Keyboard p and P
#define VHID_KEY_Q 0x14 // Keyboard q and Q
#define VHID_KEY_R 0x15 // Keyboard r and R
#define VHID_KEY_S 0x16 // Keyboard s and S
#define VHID_KEY_T 0x17 // Keyboard t and T
#define VHID_KEY_U 0x18 // Keyboard u and U
#define VHID_KEY_V 0x19 // Keyboard v and V
#define VHID_KEY_W 0x1a // Keyboard w and W
#define VHID_KEY_X 0x1b // Keyboard x and X
#define VHID_KEY_Y 0x1c // Keyboard y and Y
#define VHID_KEY_Z 0x1d // Keyboard z and Z

#define VHID_KEY_1 0x1e // Keyboard 1 and !
#define VHID_KEY_2 0x1f // Keyboard 2 and @
#define VHID_KEY_3 0x20 // Keyboard 3 and #
#define VHID_KEY_4 0x21 // Keyboard 4 and $
#define VHID_KEY_5 0x22 // Keyboard 5 and %
#define VHID_KEY_6 0x23 // Keyboard 6 and ^
#define VHID_KEY_7 0x24 // Keyboard 7 and &
#define VHID_KEY_8 0x25 // Keyboard 8 and *
#define VHID_KEY_9 0x26 // Keyboard 9 and (
#define VHID_KEY_0 0x27 // Keyboard 0 and )

#define VHID_KEY_ENTER 0x28 // Keyboard Return (ENTER)
#define VHID_KEY_ESC 0x29 // Keyboard ESCAPE
#define VHID_KEY_BACKSPACE 0x2a // Keyboard DELETE (Backspace)
#define VHID_KEY_TAB 0x2b // Keyboard Tab
#define VHID_KEY_SPACE 0x2c // Keyboard Spacebar
#define VHID_KEY_MINUS 0x2d // Keyboard - and _
#define VHID_KEY_EQUAL 0x2e // Keyboard = and +
#define VHID_KEY_LEFTBRACE 0x2f // Keyboard [ and {
#define VHID_KEY_RIGHTBRACE 0x30 // Keyboard ] and }
#define VHID_KEY_BACKSLASH 0x31 // Keyboard \ and |
#define VHID_KEY_HASHTILDE 0x32 // Keyboard Non-US # and ~
#define VHID_KEY_SEMICOLON 0x33 // Keyboard ; and :
#define VHID_KEY_APOSTROPHE 0x34 // Keyboard ' and "
#define VHID_KEY_GRAVE 0x35 // Keyboard ` and ~
#define VHID_KEY_COMMA 0x36 // Keyboard , and <
#define VHID_KEY_DOT 0x37 // Keyboard . and >
#define VHID_KEY_SLASH 0x38 // Keyboard / and ?
#define VHID_KEY_CAPSLOCK 0x39 // Keyboard Caps Lock

#define VHID_KEY_F1 0x3a // Keyboard F1
#define VHID_KEY_F2 0x3b // Keyboard F2
#define VHID_KEY_F3 0x3c // Keyboard F3
#define VHID_KEY_F4 0x3d // Keyboard F4
#define VHID_KEY_F5 0x3e // Keyboard F5
#define VHID_KEY_F6 0x3f // Keyboard F6
#define VHID_KEY_F7 0x40 // Keyboard F7
#define VHID_KEY_F8 0x41 // Keyboard F8
#define VHID_KEY_F9 0x42 // Keyboard F9
#define VHID_KEY_F10 0x43 // Keyboard F10
#define VHID_KEY_F11 0x44 // Keyboard F11
#define VHID_KEY_F12 0x45 // Keyboard F12

#define VHID_KEY_SYSRQ 0x46 // Keyboard Print Screen
#define VHID_KEY_SCROLLLOCK 0x47 // Keyboard Scroll Lock
#define VHID_KEY_PAUSE 0x48 // Keyboard Pause
#define VHID_KEY_INSERT 0x49 // Keyboard Insert
#define VHID_KEY_HOME 0x4a // Keyboard Home
#define VHID_KEY_PAGEUP 0x4b // Keyboard Page Up
#define VHID_KEY_DELETE 0x4c // Keyboard Delete Forward
#define VHID_KEY_END 0x4d // Keyboard End
#define VHID_KEY_PAGEDOWN 0x4e // Keyboard Page Down
#define VHID_KEY_RIGHT 0x4f // Keyboard Right Arrow
#define VHID_KEY_LEFT 0x50 // Keyboard Left Arrow
#define VHID_KEY_DOWN 0x51 // Keyboard Down Arrow
#define VHID_KEY_UP 0x52 // Keyboard Up Arrow

#define VHID_KEY_NUMLOCK 0x53 // Keyboard Num Lock and Clear
#define VHID_KEY_KPSLASH 0x54 // Keypad /
#define VHID_KEY_KPASTERISK 0x55 // Keypad *
#define VHID_KEY_KPMINUS 0x56 // Keypad -
#define VHID_KEY_KPPLUS 0x57 // Keypad +
#define VHID_KEY_KPENTER 0x58 // Keypad ENTER
#define VHID_KEY_KP1 0x59 // Keypad 1 and End
#define VHID_KEY_KP2 0x5a // Keypad 2 and Down Arrow
#define VHID_KEY_KP3 0x5b // Keypad 3 and PageDn
#define VHID_KEY_KP4 0x5c // Keypad 4 and Left Arrow
#define VHID_KEY_KP5 0x5d // Keypad 5
#define VHID_KEY_KP6 0x5e // Keypad 6 and Right Arrow
#define VHID_KEY_KP7 0x5f // Keypad 7 and Home
#define VHID_KEY_KP8 0x60 // Keypad 8 and Up Arrow
#define VHID_KEY_KP9 0x61 // Keypad 9 and Page Up
#define VHID_KEY_KP0 0x62 // Keypad 0 and Insert
#define VHID_KEY_KPDOT 0x63 // Keypad . and Delete

#define VHID_KEY_102ND 0x64 // Keyboard Non-US \ and |
#define VHID_KEY_COMPOSE 0x65 // Keyboard Application

#define VHID_KEY_LEFTCTRL 0xe0 // Keyboard Left Control
#define VHID_KEY_LEFTSHIFT 0xe1 // Keyboard Left Shift
#define VHID_KEY_LEFTALT 0xe2 // Keyboard Left Alt
#define VHID_KEY_LEFTMETA 0xe3 // Keyboard Left GUI
#define VHID_KEY_RIGHTCTRL 0xe4 // Keyboard Right Control
#define VHID_KEY_RIGHTSHIFT 0xe5 // Keyboard Right Shift
#define VHID_KEY_RIGHTALT 0xe6 // Keyboard Right Alt
#define VHID_KEY_RIGHTMETA 0xe7 // Keyboard Right GUI
