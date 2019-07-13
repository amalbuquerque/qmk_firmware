/* Copyright 2019 amalbuquerque
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

enum minila_layers {
  _QWERTY,        // Qwerty (default layer)
  _BASIC,         // Basic qwerty
  _F1_LAYER,      // Symbols
  _F4_LAYER       // Multimedia
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  CTL_TAB = CTL_T(KC_TAB),
  CTL_BSP = CTL_T(KC_BSPC),
  TTO_FN1 = TT(_F1_LAYER),
  TTO_FN4 = TT(_F4_LAYER),
  SPC_FN1 = LT(_F1_LAYER, KC_SPC),
  APP_FN4 = LT(_F4_LAYER, KC_APP),
  SPC_LGUI = MT(MOD_LGUI, KC_SPC),
  NKROTG = MAGIC_TOGGLE_NKRO
};

#define ___ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_BSPC,  \
    KC_ESC,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS, \
    CTL_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,                  KC_ENT, \
    KC_LSPO,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP,    KC_DELETE, \
    TTO_FN1, KC_LGUI,  KC_LALT, SPC_LGUI,     SPC_FN1,     CTL_BSP, KC_RALT, APP_FN4, KC_LEFT, KC_DOWN, TTO_FN4  \
  ),

  [_F1_LAYER] = LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___, ___, \
    ___,      ___, ___, ___, ___, KC_GRV, ___, KC_HOME, ___, ___, ___,    ___, ___,                  ___, \
    ___,       ___, ___, ___, ___, S(KC_GRV), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   KC_BSPC, ___,      ___, \
    ___,        ___, ___, ___, ___, S(KC_6), KC_END, KC_DELETE, KC_INS, KC_PGUP, KC_PGDN, ___, ___,  ___, \
    ___, ___,  ___,   ___,                      ___,                        ___, ___, ___, ___, ___, ___  \
  ),

  [_F4_LAYER] = LAYOUT(
    KC_PWR,  ___,  ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,            RESET, \
    KC_SLEP,   ___, ___, ___, ___, NKROTG, ___, ___, KC_PSCR, KC_SLCK, KC_PAUS, ___, ___,         ___, \
    ___,        ___, KC_MPRV, KC_MNXT, ___, ___, ___, ___, ___, ___,   ___, ___,                  ___, \
    ___,         KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, ___, ___, ___, ___, ___, ___, ___, ___,      ___, \
    ___, ___,  ___,   ___,                      ___,                     ___, ___, ___, ___, ___, ___  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
