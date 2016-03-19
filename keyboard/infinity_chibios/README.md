Notes on building the infinity firmware with Chibios
====================================================

1. I couldn't build the firmware in the Arch linux VM
    * Tried with GCC 5.3 and the corresponding arm-none-eabi-gcc, with both chibios versions 16.1.4 and 16.1.0 (no success building)
    * Tried with GCC 4.9 and the corresponding arm-none-eabi-gcc, with both chibios versions 16.1.4 and 16.1.0 (built, but after uploading to the keyboard, didn't work)

2. Had success in the Ubuntu 14.04 VM
    * GCC version 4.8.4, arm-none-eabi-gcc version 4.9.3, chibios version 3.0.0
