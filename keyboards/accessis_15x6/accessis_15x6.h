#ifndef ACCESSIS_15X6_H
#define ACCESSIS_15X6_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
/*
    With QMK Rows(0-8) and Cols (0-B):
    X Type        1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
    A (Rows&Cols) 06 76 16 66 26 56 46 85 05 75 15 65 25 55 35
    B (Rows&Cols) 77 17 67 27 57 47 84 04 74 14 64 24 54 34 86
    C (Rows&Cols) 18 68 28 58 48 83 03 73 13 63 23 53 33 87 07
    D (Rows&Cols) 69 29 59 49 82 02 72 12 62 22 52 32 88 08 78
    E (Rows&Cols) 2A 5A 4A 81 01 71 11 61 21 51 31 89 09 79 19
    F (Rows&Cols) 5B 4B 80 00 70 10 60 20 50 30 8A 0A 7A 1A 6A
 */
// 2017/03/18 18:28:11, AA:
// The above matrix represents what we see when looking from behind the keyboard.
// Therefore, I'll have to mirror the matrix vertically
// (Col. 1 will swap with Col. 15, Col. 2 with Col. 14, etc.)
//
// Original matrix (before mirroring it):
/* #define KEYMAP( \ */
/* 1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  \ */
/* k06, k76, k16, k66, k26, k56, k46, k85, k05, k75, k15, k65, k25, k55, k35, \ */
/* k77, k17, k67, k27, k57, k47, k84, k04, k74, k14, k64, k24, k54, k34, k86, \ */
/* k18, k68, k28, k58, k48, k83, k03, k73, k13, k63, k23, k53, k33, k87, k07, \ */
/* k69, k29, k59, k49, k82, k02, k72, k12, k62, k22, k52, k32, k88, k08, k78, \ */
/* k2A, k5A, k4A, k81, k01, k71, k11, k61, k21, k51, k31, k89, k09, k79, k19, \ */
/* k5B, k4B, k80, k00, k70, k10, k60, k20, k50, k30, k8A, k0A, k7A, k1A, k6A  \ */
/* ) \ */
// Matrix after mirror:
/* 15,  14,  13,  12,  11,  10,  9,   8,   7,   6,   5,   4,   3,   2,   1 */
#define KEYMAP( \
k35, k55, k25, k65, k15, k75, k05, k85, k46, k56, k26, k66, k16, k76, k06, \
k86, k34, k54, k24, k64, k14, k74, k04, k84, k47, k57, k27, k67, k17, k77, \
k07, k87, k33, k53, k23, k63, k13, k73, k03, k83, k48, k58, k28, k68, k18, \
k78, k08, k88, k32, k52, k22, k62, k12, k72, k02, k82, k49, k59, k29, k69, \
k19, k79, k09, k89, k31, k51, k21, k61, k11, k71, k01, k81, k4A, k5A, k2A, \
k6A, k1A, k7A, k0A, k8A, k30, k50, k20, k60, k10, k70, k00, k80, k4B, k5B  \
) \
{ \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,   k09,   k0A,   KC_NO }, \
    { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17,   k18,   k19,   k1A,   KC_NO }, \
    { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A,   KC_NO }, \
    { k30,   k31,   k32,   k33,   k34,   k35,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k46,   k47,   k48,   k49,   k4A,   k4B   }, \
    { k50,   k51,   k52,   k53,   k54,   k55,   k56,   k57,   k58,   k59,   k5A,   k5B   }, \
    { k60,   k61,   k62,   k63,   k64,   k65,   k66,   k67,   k68,   k69,   k6A,   KC_NO }, \
    { k70,   k71,   k72,   k73,   k74,   k75,   k76,   k77,   k78,   k79,   k7A,   KC_NO }, \
    { k80,   k81,   k82,   k83,   k84,   k85,   k86,   k87,   k88,   k89,   k8A,   KC_NO }, \
}

#endif
