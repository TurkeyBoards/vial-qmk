/*
Turkeyyboards Swoop Vial Firmware
*/

#pragma once

/* VIAL UID for TurkeyBoards Swoop Kit*/
#define VIAL_KEYBOARD_UID {0x13, 0xC1, 0xB2, 0xC3, 0x96, 0xC3, 0xA2, 0x86}

/* VIAL secure unlock keystroke - currently both big keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
#define OLED_DISPLAY_128X32
#define SPLIT_USB_DETECT
#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended