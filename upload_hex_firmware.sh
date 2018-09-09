#!/bin/bash
printf "The Pro Micro should be already connected by now. When you reset the controller (short the RST and GND pins), a new tty port will appear."
printf "Detecting USB port, reset your controller now.";
ls /dev/tty* > /tmp/1;
while [ -z $USB ]; do
	sleep 0.5;
	printf ".";
	ls /dev/tty* > /tmp/2;
	USB=`comm -13 /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`;
	mv /tmp/2 /tmp/1;
done;

echo "";
echo "Detected controller on USB port at $USB";

sleep 1;
echo "Will upload this $1"
avrdude -p atmega32u4 -c avr109 -P $USB -U flash:w:$1;
