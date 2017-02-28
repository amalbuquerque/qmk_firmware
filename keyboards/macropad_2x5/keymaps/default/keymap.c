#include "macropad_2x5.h"

#define _DEFAULT 0
#define _NUMBERS 1

enum macro_id {
    PARENS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = KEYMAP( /* Base */
      KC_Q,    KC_W, KC_E, KC_R, KC_T, \
      FUNC(0), KC_S, KC_D, KC_F, KC_G
    ),
    [_NUMBERS] = KEYMAP( /* Numbers */
      KC_0, KC_1, KC_2, KC_3, KC_4,      \
      KC_5, KC_6, KC_7, KC_8, M(PARENS)
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(_NUMBERS, KC_SPC)  // Tap for space, hold for NUMBERS
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case PARENS: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LSFT), TYPE(KC_9), TYPE(KC_0), UP(KC_LSFT), TYPE(KC_LEFT), END );
          }
          break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
