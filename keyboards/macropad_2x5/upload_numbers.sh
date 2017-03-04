#!/bin/bash
# ard-reset-arduino --verbose --caterina /dev/ttyACM0 && avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -D -V -U flash:w:/vagrant/macropad_2x5_numbers_2nd_worked.hex
# 2017/03/04 14:56:24, AA:
# It apparently writes successfully to the pro micro but doesn't work afterwards :/. Was only able to upload the firmware in Windows with ArduinoBuilder.exe
avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -D -V -U flash:w:/vagrant/macropad_2x5_lejboua.hex
