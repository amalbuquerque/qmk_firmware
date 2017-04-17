#include "macropad_2x5.h"

#define _DEFAULT 0
#define _WINDOW_MGMT 1

enum macro_id {
    ALTTAB,
    CUT,
    COPY,
    PASTE,
    TMUX_VIS,
    TMUX_ZOM,
    TMUX_PHR,
    TMUX_PVR,
    TMUX_NWD,
    WIN_LFT,
    WIN_RGT,
    WIN_UP,
    WIN_DW,
    WIN_FLL,
    TMUX_PN0,
    TMUX_PN1,
    TMUX_PN2,
    TMUX_PN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // 2017/04/17 19:24:20, AA: Red F5 on the bottom-left, Orange HOT_SWAP on the top-right
    // F6 , F8 , F10 , F12 , HOT_SWAP
    // F5 , F7 , F9  , F11 , Cancel
    [_DEFAULT] = KEYMAP( /* Base */
      M(CUT),    M(PASTE), M(TMUX_ZOM), M(TMUX_PVR), FUNC(0), \
      M(ALTTAB), M(COPY),  KC_MS_BTN3,  KC_MS_BTN2,  KC_MS_BTN1
    ),
    [_WINDOW_MGMT] = KEYMAP( /* Numbers */
      M(TMUX_PN1), M(TMUX_PN3), M(WIN_RGT), M(WIN_UP), KC_TRNS, \
      M(TMUX_PN0), M(TMUX_PN2), M(WIN_LFT), M(WIN_DW), M(WIN_FLL)
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(_WINDOW_MGMT, KC_X)  // Tap for space, hold for WINDOW_MGMT
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case CUT: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_X), UP(KC_LCTL), END );
          }
          break;
        case COPY: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_C), UP(KC_LCTL), END );
          }
          break;
        case PASTE: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_V), UP(KC_LCTL), END );
          }
          break;
        case ALTTAB: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LALT), TYPE(KC_TAB), UP(KC_LALT), END );
          }
          break;
        case TMUX_VIS: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_ESC), END );
          }
          break;
        case TMUX_ZOM: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Z), END );
          }
          break;
        case TMUX_PHR: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), DOWN(KC_LSFT), TYPE(KC_QUOTE), UP(KC_LSFT), END );
          }
          break;
        case TMUX_PVR: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_SLASH), END );
          }
          break;
        case TMUX_NWD: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_N), END );
          }
          break;
        case WIN_LFT: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_LEFT), UP(KC_LGUI), END );
          }
          break;
        case WIN_RGT: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_RIGHT), UP(KC_LGUI), END );
          }
          break;
        case WIN_UP: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_UP), UP(KC_LGUI), END );
          }
          break;
        case WIN_DW: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_DOWN), UP(KC_LGUI), END );
          }
          break;
        case WIN_FLL: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_BSLASH), UP(KC_LGUI), END );
          }
          break;
        case TMUX_PN0: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Q), TYPE(KC_0), END );
          }
          break;
        case TMUX_PN1: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Q), TYPE(KC_1), END );
          }
          break;
        case TMUX_PN2: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Q), TYPE(KC_2), END );
          }
          break;
        case TMUX_PN3: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_Q), TYPE(KC_3), END );
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
