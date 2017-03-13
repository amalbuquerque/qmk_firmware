#include "accessis_15x6.h"

#define QWERTY_LAYER 0
#define F1_LAYER 1
#define F2_LAYER 2
#define F3_LAYER 3
#define F4_LAYER 4
#define F5_LAYER 5

enum macro_id {
    PARENS,
    CRLY_PARENS,
    SQUR_PARENS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY_LAYER] = KEYMAP( /* Base */
      KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_F6,          KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11           ,\
      KC_GRAVE,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,     KC_TRNS,    KC_TRNS,       KC_6,           KC_7,    KC_8,    KC_9,      KC_0,    KC_MINUS         ,\
      FUNC(3),       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MS_WH_UP, KC_TRNS,    KC_MS_WH_DOWN, KC_Y,           KC_U,    KC_I,    KC_O,      KC_P,    FUNC(4)          ,\
      CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MS_BTN1,  KC_MS_BTN2, KC_MS_BTN3,    KC_H,           KC_J,    KC_K,    KC_L,      KC_SCLN, KC_ENT           ,\
      KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC__VOLUP,   KC_MUTE,    KC__VOLDOWN,   KC_N,           KC_M,    KC_COMM, KC_DOT,    KC_SLSH, SFT_T(KC_DELETE) ,\
      FUNC(7),       KC_LGUI, FUNC(6), KC_LALT, FUNC(0), FUNC(5), KC_CUT,      KC_COPY,    KC_PASTE,      CTL_T(KC_BSPC), FUNC(1), KC_RALT, KC_DELETE, FUNC(2), MO(F2_LAYER)
    ),

    [F1_LAYER] = KEYMAP( /* F1_Layer */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,   KC_TRNS, KC_MINS, KC_EQL,  KC_GRV  ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_BSPC, KC_QUOT ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_6),   KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_DELETE, KC_INS,  KC_PGUP, KC_PGDN, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [F2_LAYER] = KEYMAP( /* F2_Layer */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS ,\
      KC_TRNS, S(KC_1), S(KC_2), S(KC_3),    S(KC_4),    S(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, S(KC_6), S(KC_7), S(KC_8),    S(KC_9),    S(KC_0),   KC_TRNS ,\
      KC_TRNS, S(KC_9), S(KC_0), S(KC_LBRC), S(KC_RBRC), M(1),    KC_TRNS, KC_TRNS, KC_TRNS, M(2),    KC_QUOT, S(KC_QUOT), S(KC_MINS), S(KC_EQL), KC_TRNS ,\
      KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,    KC_TRNS,    M(3),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS
    ),

    [F3_LAYER] = KEYMAP( /* F3_Layer */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS ,\
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS ,\
      KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS, KC_TRNS, KC_TRNS, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [F4_LAYER] = KEYMAP( /* F4_Layer */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_PWR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RESET   ,\
      KC_SLEP, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [F5_LAYER] = KEYMAP( /* F5_Layer */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_SLASH,    KC_KP_MINUS, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS, KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_ASTERISK, KC_KP_PLUS,  KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS, KC_BSPC ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK,        KC_KP_0,     KC_KP_1, KC_KP_2, KC_KP_3, KC_DOT,  KC_TRNS ,\
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(F1_LAYER, KC_SPC),  // Tap for space, hold for F1_LAYER
    [1] = ACTION_LAYER_TAP_KEY(F2_LAYER, KC_ENT),  // Tap for enter, hold for F2_LAYER
    [2] = ACTION_LAYER_TAP_KEY(F4_LAYER, KC_APP),  // Tap for app, hold for F4_LAYER
    [3] = ACTION_LAYER_TAP_KEY(F3_LAYER, KC_ESC),  // Tap for esc, hold for F3_LAYER
    [4] = ACTION_LAYER_TAP_KEY(F3_LAYER, KC_BSLS), // Tap for backslash, hold for F3_LAYER
    [5] = ACTION_LAYER_TAP_TOGGLE(F3_LAYER),       // Double tap for activating F3_Layer, hold for F3_LAYER
    [6] = ACTION_LAYER_TAP_TOGGLE(F5_LAYER),  // Double tap for activating F5_LAYER, hold for F5_LAYER
    [7] = ACTION_LAYER_TAP_TOGGLE(F1_LAYER)        // Double tap for activating F1_LAYER, hold for F1_LAYER
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
        case CRLY_PARENS: // Macro M{\n\n}
            if (record->event.pressed) {
              return MACRODOWN( DOWN(KC_LSFT), TYPE(KC_LBRC), TYPE(KC_RBRC), UP(KC_LSFT), TYPE(KC_LEFT), TYPE(KC_ENT), TYPE(KC_ENT), TYPE(KC_UP), END );
            }
            break;
        case SQUR_PARENS: // Macro M[]
            if (record->event.pressed) {
              return MACRODOWN( TYPE(KC_LBRC), TYPE(KC_RBRC), TYPE(KC_LEFT), END );
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
