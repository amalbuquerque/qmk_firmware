#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum rorschach_layers {
  _QWERTY,        // Qwerty (default layer)
  _BASIC,         // Basic qwerty
  _F1_LAYER,      // Symbols
  _F2_LAYER,      // Symbols II
  _NUMBERS_LAYER, // Numbers
  _F4_LAYER,      // Multimedia
  _F5_LAYER,      // Numpad
  _TMUX_LAYER     // Tmux FTW
};

enum rorschach_keycodes {
  QWERTY = SAFE_RANGE,
  BASIC,
  SPC_FN1 = LT(_F1_LAYER, KC_SPC),
  ENT_FN2 = LT(_F2_LAYER, KC_ENT),
  APP_FN4 = LT(_F4_LAYER, KC_APP),
  ESC_NUM = LT(_NUMBERS_LAYER, KC_ESC),
  BSL_NUM = LT(_NUMBERS_LAYER, KC_BSLS),
  CTL_TAB = CTL_T(KC_TAB),
  CTL_ESC = CTL_T(KC_ESC),
  CTL_BSP = CTL_T(KC_BSPC),
  TMX_KEY = LCTL(KC_A),
  // tap toggle
  TTO_NUM = ACTION_LAYER_TAP_TOGGLE(_NUMBERS_LAYER),
  TTO_FN1 = ACTION_LAYER_TAP_TOGGLE(_F1_LAYER),
  TTO_FN5 = ACTION_LAYER_TAP_TOGGLE(_F5_LAYER),
  TTO_TMX = ACTION_LAYER_TAP_TOGGLE(_TMUX_LAYER),
  NKROTG = MAGIC_TOGGLE_NKRO,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum macro_id {
    PARENS,
    CRLY_PARENS,
    SQUR_PARENS,
    TMUX_WIN1,
    TMUX_WIN2,
    TMUX_WIN3,
    TMUX_WIN4,
    TMUX_WIN5,
    TMUX_ZOOM,
    TMUX_LWIN,
    TMUX_RWIN,
    TMUX_HSPL,
    TMUX_VSPL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty (uses Space Cadet Shifts) */
[_QWERTY] = LAYOUT(
  ESC_NUM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    BSL_NUM,
  CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_ENT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_RSPC,
  TTO_FN1, KC_LGUI, TTO_FN5, KC_LALT, SPC_FN1, TTO_NUM,                      CTL_BSP, ENT_FN2, KC_RALT, KC_DELETE, APP_FN4, TMX_KEY,
                                               KC_LGUI, TMX_KEY,    KC_LGUI, TTO_TMX
),

/* BASIC */
[_BASIC] = LAYOUT(
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTL_ESC, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_INS,  KC_GRV, KC_LBRC, KC_RBRC, KC_LALT, KC_SPC,                     KC_BSPC, KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                                              KC_ENT, KC_BSPC,    KC_ENT, KC_DELETE
),

[_F1_LAYER] = LAYOUT(
  KC_TAB,  _______, _______, _______, _______, KC_GRV,                      _______, KC_HOME,   _______, KC_MINS, KC_EQL,  KC_GRV  ,
  _______, _______, _______, _______, _______, S(KC_GRV),                   KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_BSPC, KC_QUOT ,
  _______, _______, _______, _______, _______, S(KC_6),                     KC_END,  KC_DELETE, KC_INS,  KC_PGUP, KC_PGDN, _______ ,
  _______, _______, _______, _______, _______, _______,                     _______, _______,   _______, _______, _______, _______ ,
                                               _______, _______,   _______, _______
),

[_F2_LAYER] = LAYOUT(
  _______, S(KC_1), S(KC_2), S(KC_3),    S(KC_4),    S(KC_5),                      S(KC_6), S(KC_7), S(KC_8),    S(KC_9),    S(KC_0),   _______ ,
  _______, S(KC_9), S(KC_0), S(KC_LBRC), S(KC_RBRC), M(0),                         M(1),    KC_QUOT, S(KC_QUOT), S(KC_MINS), S(KC_EQL), _______ ,
  _______, KC_LBRC, KC_RBRC, _______,    _______,    M(2),                         _______, _______, _______,    _______,    _______,   _______ ,
  _______, _______, _______, _______,    _______,    _______,                      _______, _______, _______,    _______,    _______,   _______ ,
                                                     _______, _______,    _______, _______
),

[_NUMBERS_LAYER] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ ,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ ,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                       KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______ ,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______ ,
                                               _______, _______,    _______, _______
),

[_F4_LAYER] = LAYOUT(
  KC_PWR,  _______, QWERTY , BASIC  , _______, NKROTG ,                      _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET   ,
  KC_SLEP, _______, KC_MPRV, KC_MNXT, _______, _______,                      _______, _______, _______, _______, _______, _______ ,
  _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, _______,                      _______, _______, _______, _______, _______, _______ ,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______ ,
                                               _______, _______,    _______, _______
),

[_F5_LAYER] = LAYOUT(
  _______, _______, _______, _______, KC_KP_SLASH,    KC_KP_MINUS,                KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______ ,
  _______, _______, _______, _______, KC_KP_ASTERISK, KC_KP_PLUS,                 KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_BSPC, _______ ,
  _______, _______, _______, _______, KC_NLCK,        KC_KP_0,                    KC_KP_1, KC_KP_2, KC_KP_3, KC_DOT,  _______, _______ ,
  _______, _______, _______, _______, _______,        _______,                    _______, _______, _______, _______, _______, _______ ,
                                                      _______, _______,  _______, _______
),

[_TMUX_LAYER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______ ,
  _______, M(3),    M(4),    M(5),    M(6),    M(7),                       M(8),    M(9),    M(10),   M(11),   M(12),   _______ ,
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______ ,
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______ ,
                                               _______, _______,  _______, _______
)

};

/* This functions is called whenever a layer changes */
// in our case we're calling the `update_tri_layer_state`, meaning
// we will activate the _ADJUST layer if both NUMBERS and NUMBERS2
// This is useful if we want to set the lights differently based
// on the active layer for example
/* uint32_t layer_state_set_user(uint32_t state) { */
/*   return update_tri_layer_state(state, _NUMBERS, _NUMBERS2, _ADJUST); */
/* } */

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _QWERTY);
        layer_off(_BASIC);
        layer_off(_F1_LAYER);
        layer_off(_F2_LAYER);
        layer_off(_NUMBERS_LAYER);
        layer_off(_F4_LAYER);
        layer_off(_F5_LAYER);
        layer_off(_TMUX_LAYER);
      }
      return false;
      break;
    case BASIC:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _BASIC);
        layer_off(_QWERTY);
        layer_off(_F1_LAYER);
        layer_off(_F2_LAYER);
        layer_off(_NUMBERS_LAYER);
        layer_off(_F4_LAYER);
        layer_off(_F5_LAYER);
        layer_off(_TMUX_LAYER);
      }
      return false;
      break;
  }
  return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case PARENS: // Macro ()
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LSFT), TYPE(KC_9), TYPE(KC_0), UP(KC_LSFT), TYPE(KC_LEFT), END );
            }
            break;
        case CRLY_PARENS: // Macro {\n\n}
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LSFT), TYPE(KC_LBRC), TYPE(KC_RBRC), UP(KC_LSFT), TYPE(KC_LEFT), TYPE(KC_ENT), TYPE(KC_ENT), TYPE(KC_UP), END );
            }
            break;
        case SQUR_PARENS: // Macro []
            if (record->event.pressed) {
                return MACRODOWN( TYPE(KC_LBRC), TYPE(KC_RBRC), TYPE(KC_LEFT), END );
            }
            break;
        case TMUX_WIN1: // Macro Tmux Win1
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_1), END );
            }
            break;
        case TMUX_WIN2: // Macro Tmux Win2
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_2), END );
            }
            break;
        case TMUX_WIN3: // Macro Tmux Win3
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_3), END );
            }
            break;
        case TMUX_WIN4: // Macro Tmux Win4
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_4), END );
            }
            break;
        case TMUX_WIN5: // Macro Tmux Win5
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_5), END );
            }
            break;
        case TMUX_ZOOM: // Macro Tmux Zoom toggle
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Z), END );
            }
            break;
        case TMUX_LWIN: // Macro Tmux Left Window
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), TYPE(KC_H), UP(KC_LCTL), END );
            }
            break;
        case TMUX_RWIN: // Macro Tmux Right Window
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), TYPE(KC_L), UP(KC_LCTL), END );
            }
            break;
        case TMUX_HSPL: // Macro Tmux Horizontal Split
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), DOWN(KC_RSFT), TYPE(KC_QUOT), UP(KC_RSFT), END );
            }
            break;
        case TMUX_VSPL: // Macro Tmux Vertical Split
            if (record->event.pressed) {
                return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_SLSH), END );
            }
            break;
    }
    return MACRO_NONE;
};
