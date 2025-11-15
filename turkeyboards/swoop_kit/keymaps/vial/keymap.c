 /* Copyright 2020 Naoki Katahira
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYS,
  _OP
};

/* Keycodes for the layers */
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define SYS   MO(_SYS)
#define OP    MO(_OP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | LCTL |LOWER | Ent  |     |Space |RAISE | Alt |
 *              `--------------------'     `--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                   KC_LCTL, LOWER, KC_ENT,        KC_SPC,  RAISE,  KC_LALT
),
/* LOWER
 * ,---------------------------------.     ,----------------------------------.
 * |  !  |   @  |   #  |   $  |   %  |     |   ^  |   &  |   *  |   (  |   )  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |  =  |   _  |   `   |  ~  |  |   |     |   \  |   -  |   +  |   {  |   }  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | LCTL |LOWER | Ent  |     |Space |RAISE | Alt |
 *              `--------------------'     `--------------------'
 */
[_LOWER] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_EQL, KC_UNDS, KC_GRV, KC_TILDE, KC_PIPE,      KC_BSLS, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,
                   _______, _______, _______,      _______,  _______, _______
),
/* RAISE
 * ,---------------------------------.     ,----------------------------------.
 * |  F1 |  F2  |  F3  |  F4  |  F5  |     |      |      |      |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  F6 |  F7  |  F8  |  F9  |  F10 |     |      | Left | Dowm |  Up  |Right |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * | F11 | F12  |      |   [  |   ]  |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | LCTL |LOWER | Ent  |     |Space |RAISE | Alt |
 *              `--------------------'     `--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_F11,  KC_F12,   XXXXXXX, KC_LBRC, KC_RBRC,     XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______,      _______, _______, _______
),

/* ADJUST
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______,      _______, _______, _______
  ),
/* MO(4) 
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_SYS] = LAYOUT(
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______,      _______, _______, _______
  ),
/* MO(5) 
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |     |      |      |      |      |     |      |      |      |      |      |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */

[_OP] = LAYOUT(
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______,      _______, _______, _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
#define ENC_NONE { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) }

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_MOD, RGB_TOG) },
    [3] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_DOWN, KC_UP)   },
    [4] = ENC_NONE,
    [5] = ENC_NONE
};
#endif
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  oled_on();
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
   }
  return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

  // Caps lock status
//led_t led_state = host_keyboard_led_state();


// 'Turkeyboards', 128x32px
static void render_logo(void) {
    //static const char PROGMEM logo[] = {
static const unsigned char PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0xE0, 0xE0, 0xF0, 0xD8,
    0xD8, 0x98, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x18, 0x1C, 0x1E, 0x3F, 0x7F,
    0xFE, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0,
    0xF0, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFC, 0xFE, 0x16, 0x36, 0xF6,
    0xF6, 0x36, 0x36, 0x06, 0xE6, 0xE6,
    0x06, 0xC6, 0xE6, 0x06, 0x06, 0xE6,
    0xC6, 0x66, 0xE6, 0xC6, 0x06, 0xFE,
    0xFE, 0x86, 0xE6, 0x66, 0x06, 0x86,
    0xC6, 0x66, 0x66, 0xC6, 0x86, 0x66,
    0xE6, 0x86, 0x06, 0xC6, 0xE6, 0x06,
    0xFE, 0xFE, 0xE6, 0x66, 0xE6, 0xC6,
    0x86, 0xC6, 0xE6, 0x66, 0xE6, 0xC6,
    0x06, 0x46, 0x66, 0x66, 0xE6, 0xC6,
    0x06, 0x06, 0xE6, 0xC6, 0x66, 0xE6,
    0xC6, 0x06, 0xC6, 0xE6, 0x66, 0xFE,
    0xFE, 0x06, 0x86, 0xC6, 0xE6, 0x66,
    0x66, 0x06, 0x06, 0xFE, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xFE, 0xE7, 0x81, 0x1C, 0x3E,
    0x3E, 0x3E, 0xBC, 0xD1, 0xFF, 0x8E,
    0x36, 0x7B, 0xFB, 0xFB, 0x7B, 0x33,
    0x06, 0xFC, 0xF8, 0x01, 0x0F, 0xFF,
    0xFF, 0xFF, 0xFB, 0xC0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00,
    0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00,
    0x07, 0x0F, 0x0C, 0x0F, 0x0F, 0x00,
    0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00,
    0x00, 0x0F, 0x0F, 0x03, 0x0F, 0x0C,
    0x00, 0x07, 0x0F, 0x0D, 0x0D, 0x0D,
    0x05, 0x30, 0x33, 0x3F, 0x1E, 0x0F,
    0x01, 0x00, 0x0F, 0x0F, 0x0C, 0x0C,
    0x0F, 0x03, 0x07, 0x0F, 0x0C, 0x0C,
    0x0F, 0x07, 0x00, 0x07, 0x0F, 0x0D,
    0x0F, 0x0F, 0x04, 0x00, 0x0F, 0x0F,
    0x00, 0x00, 0x00, 0x03, 0x07, 0x0F,
    0x0C, 0x0F, 0x0F, 0x00, 0x0C, 0x0D,
    0x0D, 0x0F, 0x0F, 0x06, 0x00, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x80, 0xC1,
    0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF9, 0xF3, 0xC6, 0x06, 0x04, 0x04,
    0x04, 0x06, 0x07, 0x03, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x9E, 0x9E, 0xBE, 0xF6, 0xF6,
    0x40, 0xFC, 0xF8, 0xF0, 0xF0, 0xF8,
    0xFC, 0x78, 0xF8, 0xFC, 0x8C, 0xFC,
    0xF8, 0x60, 0xF8, 0xFC, 0x8C, 0x8C,
    0xF8, 0x70, 0x00, 0xFC, 0xF8, 0x8C,
    0xFC, 0xF8, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFE, 0xFE, 0x38,
    0xFC, 0xCE, 0x82, 0x00, 0x8C, 0x8C,
    0xFF, 0xFB, 0x80, 0x00, 0x0C, 0xFE,
    0xFE, 0x8C, 0x8C, 0x88, 0x00, 0x00,
    0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x70, 0x78, 0x7C, 0x7E, 0xFF,
    0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xCF,
    0xC6, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC0, 0xC0, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1F, 0x1F, 0x18, 0x18, 0xF8,
    0x80, 0xC0, 0x60, 0x60, 0x30, 0x30,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x19, 0x19, 0x19,
    0x19, 0x18, 0x18, 0x19, 0x19, 0x19,
    0x18, 0x19, 0x19, 0x18, 0x18, 0x19,
    0x19, 0x19, 0x18, 0x18, 0x18, 0x19,
    0x19, 0x19, 0x18, 0x18, 0x18, 0x1F,
    0x1F, 0x19, 0x19, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x19,
    0x19, 0x18, 0x18, 0x19, 0x19, 0x18,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x18,
    0x18, 0x18, 0x19, 0x19, 0x19, 0x19,
    0x18, 0x18, 0x18, 0x1F, 0x00, 0x00,
    0x00, 0x00,
};

    oled_write_raw_P((const char *)logo, sizeof(logo));

}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

char wpm[4];
char layer_misc[7];

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

static void render_status(void) {
    oled_write_P(PSTR("layer "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust"), false);
            break;
        case _SYS:
            oled_write_P(PSTR("System"), false);
            break;
        case _OP:
            oled_write_P(PSTR("Operator"), false);
            break;
        default:
            sprintf(layer_misc, "MO(%01d) ", get_highest_layer(layer_state));
	    oled_write(layer_misc, false);
            break;
    }

    oled_write_P(PSTR("  "), false);
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write(wpm, false);
    oled_write_P(PSTR(" wpm\n"), false);
    //oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#endif // OLED_ENABLE

