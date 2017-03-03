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
    TMUX_REN,
    TMUX_NWD,
    WIN_LFT,
    WIN_RGT,
    WIN_FLL,
    TMUX_WD0,
    TMUX_WD1,
    TMUX_WD2,
    TMUX_WD3,
    TMUX_WD4,
    TMUX_WD5,
    PARENS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = KEYMAP( /* Base */
      M(CUT),    M(PASTE), M(TMUX_ZOM), M(TMUX_PVR), FUNC(0), \
      M(ALTTAB),  M(COPY), M(TMUX_VIS), M(TMUX_PHR), M(TMUX_NWD)
    ),
    [_WINDOW_MGMT] = KEYMAP( /* Numbers */
      M(TMUX_WD1), M(TMUX_WD3), M(TMUX_WD5), M(WIN_RGT), M(WIN_FLL), \
      M(TMUX_WD0), M(TMUX_WD2), M(TMUX_WD4), M(WIN_LFT), M(TMUX_REN)
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
        case TMUX_REN: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_COMMA), END );
          }
          break;
        case TMUX_NWD: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_N), END );
          }
          break;
        case WIN_LFT: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), DOWN(KC_LALT), TYPE(KC_LEFT), UP(KC_LALT), UP(KC_LCTL), END );
          }
          break;
        case WIN_RGT: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), DOWN(KC_LALT), TYPE(KC_RGHT), UP(KC_LALT), UP(KC_LCTL), END );
          }
          break;
        case WIN_FLL: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LGUI), TYPE(KC_BSLASH), UP(KC_LGUI), END );
          }
          break;
        case TMUX_WD0: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_0), END );
          }
          break;
        case TMUX_WD1: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_1), END );
          }
          break;
        case TMUX_WD2: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_2), END );
          }
          break;
        case TMUX_WD3: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_3), END );
          }
          break;
        case TMUX_WD4: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_4), END );
          }
          break;
        case TMUX_WD5: // Macro M()
          if (record->event.pressed) {
            return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_A), UP(KC_LCTL), TYPE(KC_5), END );
          }
          break;
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
