#!/bin/bash
ls /dev/tty* > /tmp/1
echo "Reset your Pro Micro now"
while [ -z $USB ]; do
  echo "Waiting"
  sleep 1
  ls /dev/tty* > /tmp/2
  USB=`diff /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`
done
