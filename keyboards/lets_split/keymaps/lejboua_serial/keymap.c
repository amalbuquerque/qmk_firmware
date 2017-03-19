#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY_LAYER 0
#define F1_LAYER 1
#define F2_LAYER 2
#define NUMBERS_LAYER 3
#define F4_LAYER 4
#define F5_LAYER 5

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum macro_id {
    PARENS,
    CRLY_PARENS,
    SQUR_PARENS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[QWERTY_LAYER] = KEYMAP( \
  FUNC(3),       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,           KC_U,    KC_I,    KC_O,      KC_P,    FUNC(4)          ,\
  CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,           KC_J,    KC_K,    KC_L,      KC_SCLN, KC_ENT           ,\
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,           KC_M,    KC_COMM, KC_DOT,    KC_SLSH, SFT_T(KC_DELETE) ,\
  FUNC(7),       KC_LGUI, FUNC(6), KC_LALT, FUNC(0), FUNC(5), CTL_T(KC_BSPC), FUNC(1), KC_RALT, KC_DELETE, FUNC(2), MO(F2_LAYER)
),

[F1_LAYER] = KEYMAP( \
  KC_TAB,  _______, _______, _______, _______, KC_GRV,    _______, KC_HOME,   _______, KC_MINS, KC_EQL,  KC_GRV  ,\
  _______, _______, _______, _______, _______, S(KC_GRV), KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_BSPC, KC_QUOT ,\
  _______, _______, _______, _______, _______, S(KC_6),   KC_END,  KC_DELETE, KC_INS,  KC_PGUP, KC_PGDN, _______ ,\
  _______, _______, _______, _______, _______, _______,   _______, _______,   _______, _______, _______, _______
),

[F2_LAYER] = KEYMAP( \
  _______, S(KC_1), S(KC_2), S(KC_3),    S(KC_4),    S(KC_5), S(KC_6), S(KC_7), S(KC_8),    S(KC_9),    S(KC_0),   _______ ,\
  _______, S(KC_9), S(KC_0), S(KC_LBRC), S(KC_RBRC), M(1),    M(2),    KC_QUOT, S(KC_QUOT), S(KC_MINS), S(KC_EQL), _______ ,\
  _______, KC_LBRC, KC_RBRC, _______,    _______,    M(3),    _______, _______, _______,    _______,    _______,   _______ ,\
  _______, _______, _______, _______,    _______,    _______, _______, _______, _______,    _______,    _______,   _______
),

[NUMBERS_LAYER] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ ,\
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ ,\
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______ ,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[F4_LAYER] = KEYMAP( \
  KC_PWR,  _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET   ,\
  KC_SLEP, _______, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______ ,\
  _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______, _______ ,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[F5_LAYER] = KEYMAP( \
  _______, _______, _______, _______, KC_KP_SLASH,    KC_KP_MINUS, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______,\
  _______, _______, _______, _______, KC_KP_ASTERISK, KC_KP_PLUS,  KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_BSPC, _______,\
  _______, _______, _______, _______, KC_NLCK,        KC_KP_0,     KC_KP_1, KC_KP_2, KC_KP_3, KC_DOT,  _______, _______,\
  _______, _______, _______, _______, _______,        _______,     _______, _______, _______, _______, _______, _______
)

};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(F1_LAYER, KC_SPC),  // Tap for space, hold for F1_LAYER
    [1] = ACTION_LAYER_TAP_KEY(F2_LAYER, KC_ENT),  // Tap for enter, hold for F2_LAYER
    [2] = ACTION_LAYER_TAP_KEY(F4_LAYER, KC_APP),  // Tap for app, hold for F4_LAYER
    [3] = ACTION_LAYER_TAP_KEY(NUMBERS_LAYER, KC_ESC),  // Tap for esc, hold for NUMBERS_LAYER
    [4] = ACTION_LAYER_TAP_KEY(NUMBERS_LAYER, KC_BSLS), // Tap for backslash, hold for NUMBERS_LAYER
    [5] = ACTION_LAYER_TAP_TOGGLE(NUMBERS_LAYER),       // Double tap for activating F3_Layer, hold for NUMBERS_LAYER
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
