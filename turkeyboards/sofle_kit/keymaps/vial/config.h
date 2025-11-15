#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

// Vial Support
#define VIAL_KEYBOARD_UID {0x15, 0xB6, 0x6A, 0xAB, 0x35, 0x37, 0xF9, 0x6F}

#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
#define NUM_ENCODERMAP_LAYERS 6
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define SPLIT_USB_DETECT
#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended