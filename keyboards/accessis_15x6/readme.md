accessis_15x6 keyboard firmware
======================

## Lejboua NOTES!

Copy first the 49-teensy.rules file to /etc/udev/rules.d/ and/or /lib/udev/rules.d, chmod 666 and then restart udev:

vagrant@ubuntu-14:/vagrant$ sudo cp 49-teensy.rules /etc/udev/rules.d/
vagrant@ubuntu-14:/vagrant$ sudo chmod 666 /etc/udev/rules.d/49-teensy.rules
vagrant@ubuntu-14:/vagrant$ sudo service udev restart
udev stop/waiting
udev start/running, process 1469

Then, cloned the teensy_loader_cli and compiled it:
cd ~
git clone https://github.com/PaulStoffregen/teensy_loader_cli
cd teensy_loader_cli
make

Then:
vagrant@ubuntu-14:~/teensy_loader_cli$ cd ~/teensy_loader_cli
# Still w/ the Teensy in "normal" mode, with -w flag, it will wait for the Teensy bootloader to appear
vagrant@ubuntu-14:~/teensy_loader_cli$ ./teensy_loader_cli --mcu=atmega32u4 -w /vagrant/accessis_15x6_default.hex
# Press the Teensy reset button
# And it ends. To check if it went well, lsusb should now show the VendorId:ProductId defined in my Firmware
vagrant@ubuntu-14:~/teensy_loader_cli$ lsusb
Bus 001 Device 006: ID feed:6060
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub

## Quantum MK Firmware

For the full Quantum feature list, see [the parent readme](/).

## Building

Download or clone the whole firmware and navigate to the keyboards/accessis_15x6 folder. Once your dev env is setup, you'll be able to type `make` to generate your .hex - you can then use the Teensy Loader to program your .hex file. 

Depending on which keymap you would like to use, you will have to compile slightly differently.

### Default

To build with the default keymap, simply run `make default`.

### Other Keymaps

Several version of keymap are available in advance but you are recommended to define your favorite layout yourself. To define your own keymap create a folder with the name of your keymap in the keymaps folder, and see keymap documentation (you can find in top readme.md) and existant keymap files.

To build the firmware binary hex file with a keymap just do `make` with a keymap like this:

```
$ make [default|jack|<name>]
```

Keymaps follow the format **__\<name\>.c__** and are stored in the `keymaps` folder.
