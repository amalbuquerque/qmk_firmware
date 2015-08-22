#include "keymap_common.h"

/*
 * lejboua's custom Infinity config
 * ===============================
 *
 * Based on the njbair layout
 * https://github.com/njbair/tmk_keyboard/blob/njbair/keyboard/infinity/keymap_njbair.c
 * with my changes.
 *
 * BUILD COMMANDS:
 *
 * $ make KEYMAP=lejboua clean
 * $ make KEYMAP=lejboua
 * Upload the build/infinity.bin with the kii-dfu program
 * (first press the button in the back of the infinity
 *  to activate the bootloader)
 * OR
 * $ sudo dfu-util -D build/infinity.bin -d XXXX:XXXX
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer (QWERTY)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|  \|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|;F4|  '| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Del|
     * |-----------------------------------------------------------'
     * |Fn1  |GUI|Alt  |       Space/Fn2       |Alt  |Fn1|App| Fn3 |
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV ,BSLS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,      \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   FN4 ,QUOT,     ENT ,      \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,DEL,  \
        FN1 ,LGUI,LALT,               FN2,                     RALT,FN1 ,APP ,FN3 ),

    /* Function 1 Layer
     * ,-----------------------------------------------------------.
     * |PWR| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|ShT|Tab| ShT = Shift+Tab
     * |-----------------------------------------------------------|
     * |Caps |F13|F14|F15|F16|   |   |Hom|End|   |Pau|   |   | Del |
     * |-----------------------------------------------------------|
     * |Ctrl  |F17|F18|F19|F20| ` |Lef|Dow| Up|Rig| Bs|   | Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |VoD|VoU|Mut|Ply|   |End|Del|Ins|PgD|PgU|      |F21|
     * |-----------------------------------------------------------'
     * |Fn1  |Gui| Alt |        Fn2            | Alt |Fn1|   | Fn3 |
     * `-----------------------------------------------------------'
     */
    [1] = KEYMAP( \
        PWR , F1 ,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10,   F11 ,F12, FN5 , TAB, \
        CAPS,F13 , F14, F15, F16,  NO,  NO,HOME,END , NO ,PAUS,   NO  ,NO , DEL ,      \
        TRNS,F17 , F18, F19, F20, GRV,LEFT,DOWN,  UP,RGHT,   BSPC,NO  ,     TRNS,      \
        TRNS,VOLD,VOLU,MUTE,MPLY,  NO, END, DEL,   INS ,PGDN, PGUP,          NO , F21, \
        FN1 ,TRNS,TRNS,               FN2,                     TRNS, FN1, NO , FN3),

    /* Function 2 Layer
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |VoU|   |   |   |   |   |   |Psc|Slk|Pau|   |   |     |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|Pre|Nex|   |   |   |   |   |   |   |   | Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |Mut|   |   |   |   |   |   |   |   |   |      |   |
     * |-----------------------------------------------------------'
     * |Fn1  |Gui| Alt |         Fn2           | Alt |Fn1|   | Fn3 |
     * `-----------------------------------------------------------'
     */
    [2] = KEYMAP( \
        NO  ,NO  , NO , NO , NO , NO , NO , NO , NO , NO , NO ,   NO  ,NO , NO  ,NO  , \
        NO  ,VOLU, NO , NO , NO ,  NO,  NO,NO  ,PSCR,SLCK,PAUS,   NO  ,NO , NO  ,      \
        TRNS,VOLD,MPRV,MNXT, NO ,  NO,NO  ,NO  , NO ,NO  ,   NO  ,NO  ,    TRNS ,      \
        TRNS,MUTE,NO  ,NO  ,NO  ,  NO, NO , NO ,   NO  ,NO  , NO  ,          NO  ,NO , \
        FN1 ,TRNS,TRNS,               FN2,                     TRNS, FN1, NO , FN3)
};



/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),                    // Fn0 Dummy
    [1] = ACTION_LAYER_MOMENTARY(1),                    // Fn1 Activates Layer 1
    [2] = ACTION_LAYER_TAP_KEY(1, KC_SPC),              // Fn2 (on Space) Activates Layer 1
    [3] = ACTION_LAYER_MOMENTARY(2),                    // Fn3 Activates Layer 2

    // 2015-08-11, AA: Removed Fn4 from Enter
    // [4] = ACTION_LAYER_TAP_KEY(2, KC_ENT),              // Fn4 (on Enter) Activates Layer 2
    // [5] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_SCLN),       // Fn5 (on ;) Activates RCtrl
    // [6] = ACTION_MODS_KEY(MOD_LSFT, KC_TAB) 		// Fn6 (on Fn1+`) Shift+Tab

    [4] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_SCLN),       // Fn4 (on ;) Activates RCtrl
    [5] = ACTION_MODS_KEY(MOD_LSFT, KC_TAB) 		// Fn5 (on Fn1+`) Shift+Tab
};
