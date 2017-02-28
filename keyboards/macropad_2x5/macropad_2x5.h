#ifndef MACROPAD_2x5_H
#define MACROPAD_2x5_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, \
    k10, k11, k12, k13, k14  \
) \
{ \
    { k00, k01, k02, k03, k04 }, \
    { k10, k11, k12, k13, k14 }, \
}

#endif
