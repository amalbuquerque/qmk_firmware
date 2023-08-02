/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY

#define RGBLIGHT_LAYERS

#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif  // !NO_DEBUG
#ifndef NO_PRINT
#    define NO_PRINT
#endif  // !NO_PRINT
