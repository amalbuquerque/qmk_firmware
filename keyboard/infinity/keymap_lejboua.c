#include "keymap_common.h"

#define QWERTY_LAYER 0
#define F1_LAYER 1
#define F2_LAYER 2
/*
 * lejboua's custom Infinity config
 * ===============================
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer (QWERTY)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|  \|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L| ; |F4'| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Del|
     * |-----------------------------------------------------------'
     * |F1L  |GUI|Alt  |       Space/F1L       |Alt  |F1L|App| F2L |
     * `-----------------------------------------------------------'
     */
    [QWERTY_LAYER] = KEYMAP( \
        ESC,       1,    2,   3,   4,  5,   6,   7,   8,    9,    0,          MINS, EQL,  GRV , BSLS, \
        TAB,       Q,    W,   E,   R,  T,   Y,   U,   I,    O,    P,          LBRC, RBRC, BSPC,       \
        FN6,       A,    S,   D,   F,  G,   H,   J,   K,    L,    SCLN,       FN3, ENT,                \
        LSFT,      Z,    X,   C,   V,  B,   N,   M,   COMM, DOT,  SLSH,       RSFT, DEL,              \
        FN4, LGUI, LALT,               FN0,                         RALT, FN4, APP, FN5 ),

    /* Function 1 Layer
     * ,-----------------------------------------------------------.
     * |PWR| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
     * |-----------------------------------------------------------|
     * |Caps |F13|F14|F15|F16| ` |   |Hom|End|   |Pau|   |   | Del |
     * |-----------------------------------------------------------|
     * |Ctrl  | ( | ) | { | } | ~ |Lef|Dow| Up|Rig| Bs|   | Enter  | ~ = Shift+`
     * |-----------------------------------------------------------|
     * |Shift   | [ | ] |Mut|Ply| ^ |End|Del|Ins|PgD|PgU|      |F21|
     * |-----------------------------------------------------------'
     * |F1L  |Gui| Alt |        F1L            | Alt |Fn1|   | F2L |
     * `-----------------------------------------------------------'
     */
    [F1_LAYER] = KEYMAP( \
        TRNS,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  TRNS, TRNS, \
        TRNS, F13,  F14,  F15,  F16,  GRV,  TRNS, HOME, END,  TRNS, PAUS, TRNS, TRNS, DEL,        \
        TRNS, FN10, FN11, FN12, FN13,  FN1, LEFT, DOWN, UP,   RGHT, BSPC, TRNS, TRNS,          \
        TRNS, LBRC, RBRC, MUTE, MPLY, FN2, END,  DEL,  INS,  PGUP, PGDN, TRNS, F21,           \
        TRNS, TRNS, TRNS,               TRNS,                       TRNS, TRNS, TRNS, TRNS ),

    /* Function 2 Layer
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |Psc|Slk|Pau|   |   |     |
     * |-----------------------------------------------------------|
     * |Ctrl  |   |Pre|Nex|   |   |   |   |   |   |   |   | Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |VoD|VoU|Mut|Ply|   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------'
     * |F1L  |Gui| Alt |         F1L           | Alt |F1L|   | F2L |
     * `-----------------------------------------------------------'
     */
    [F2_LAYER] = KEYMAP( \
        PWR,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, RESET,\
        SLEP, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PSCR, SLCK, PAUS, TRNS, TRNS, TRNS       ,\
        TRNS, TRNS, MPRV, MNXT, TRNS, FN7, FN8, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS             ,\
        TRNS, VOLD, VOLU, MUTE, MPLY, FN9, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS             ,\
        TRNS, TRNS, TRNS,               TRNS,                       TRNS, TRNS, TRNS, TRNS)
};

enum macro_id {
    PARENS,
    CRLY_PARENS,
    SQUR_PARENS
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(F1_LAYER, KC_SPC),       // Fn0 (on Space) activates Layer 1
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),            // Fn5 (on Fn1+G) Shift + `
    [2] = ACTION_MODS_KEY(MOD_LSFT, KC_6),              // Fn6 (on Fn1+B) Shift + 6
    [3] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_QUOT),       // Fn3 (on ') ' or Ctrl
    // 2016/03/12 23:07:47, AA: Old normal F1 modifiers
    /* [4] = ACTION_LAYER_MOMENTARY(F1_LAYER),             // Fn4 activates Layer 1 */
    /* [5] = ACTION_LAYER_MOMENTARY(F2_LAYER)              // Fn5 activates Layer 2 */
    [4] = ACTION_LAYER_TAP_TOGGLE(F1_LAYER),             // Fn4 activates Layer 1
    [5] = ACTION_LAYER_TAP_TOGGLE(F2_LAYER),             // Fn5 activates Layer 2
    [6] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),         // Fn6 Ctrl or Tab (a la Planck)
    [7] = ACTION_MACRO(PARENS),                          // Fn2 + G = M()
    [8] = ACTION_MACRO(CRLY_PARENS),                     // Fn2 + H = M{}
    [9] = ACTION_MACRO(SQUR_PARENS),                     // Fn2 + B = M[]
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_9),              // (
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_0),              // )
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),           // {
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)            // }
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
