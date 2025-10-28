## Lejboua's Iris layout

Based on: [Jerry's Iris R4 Layout](https://imgur.com/a/JLytcqS)

To compile the firmware:

```
$ cd qmk_firmware
$ make keebio/iris/rev5:lejboua
```

To flash the firmware:

```
$ cd qmk_firmware
$ make keebio/iris/rev5:lejboua:flash
```

Using `qmk` tool, to compile and flash:

```
qmk compile -kb keebio/iris/rev5 -km lejboua

qmk flash -kb keebio/iris/rev5 -km lejboua
```
