# Massdrop CTRL Keyboard Splash LED

adding LED Splash effect with the provided QMK software.

## What's different (or added) from the forked project: (root as project folder)
`+ /hid_listen.exe`

`+ /massdrop_ctrl_default.bin`

`+ /massdrop_ctrl_valen214.bin`

`+ /massdrop_ctrl_valen_activate_on_press.bin`

`+ /mdloader_linux`

`+ /mdloader_windows.exe`

`+ /qmktoolbox.exe`

`+ /.build/*`

`+ /keyboards/massdrop/ctrl/keymaps/valen214/*`

`+ /keyboards/massdrop/ctrl/keymaps/valen214_activate_on_press/*`


other changes are unintentional or not important.

## How to use:
### Build yourself
1) have everything set up (to a point where you can compile and flash driver)
2) `make massdrop/ctrl:valen214`
3) `./.build/mdloader_windows.exe --first --download massdrop_ctrl_valen214.bin --restart`
(I am sorry that I am using MSYS)
4) `Fn + B` or use the pin to reset
5) Done

### qmk toolbox
1) bin file inside /.build/

fullstop.

### (Currently Available) Settings
`Fn + P`: Toggle background and wave on/off


## Implementation:
basically all changes happen only in `/keyboards/massdrop/ctrl/keymaps/valen214/keymap.c`:
Inspired by [LastContinue's Post](https://www.massdrop.com/talk/9382/how-to-configure-your-ctrl-keyboard/2201429),
by abusing `led_instructions_t` to set the led of each individual key only in `keymap.c` (It is understood to be very inefficient, but one benefit of this is being more prone to future changes (if any, ok I know there is very little) and slightly more portable (more below)).

one core function is `unsigned char ktli(uint16_t keycode);`
where you input the keycode to return the id of the led light that key correspond to (as mentioned in the post).
Therefore, ideally, changing this function alone is enough to use the code on other QMK 87 keyboards (assumption is made that the parent project from massdrop is identical to QMK's, but that's not true, I am unable to compile the code with QMK's firmware fork, didn't bother to debug).

## Known bugs/limitations
~~- double click a key will reset the original "wave front"~~
- not really appealing when typing in a fast speed (I don't have a led keyboards that have splashing so I don't know what the effect should have looked like. I am just doing this by imagination. # It is easy to add limit to distance traveled by the light, I would try if it has any positive effect)
~~- function keys (F1 - F12) and navigation keys (Ins, Home) are not working. (funtion keys are little bit tricky, but navigation keys are ~~easily implemented by updating `KEY_POSITION_MAP`)

This project is just for fun and please don't be serious 😆.



~~a copy of the above readme is in `/keyboards/massdrop/ctrl/`, NO~~

below is the content from the original readme

# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Build Status](https://travis-ci.org/qmk/qmk_firmware.svg?branch=master)](https://travis-ci.org/qmk/qmk_firmware)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](http://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](http://www.ergodox-ez.com) keyboard, and the [Clueboard product line](http://clueboard.co/).

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are hosted on [Gitbook](https://www.gitbook.com/book/qmk/firmware/details) and [GitHub](/docs/) (they are synced). You can request changes by making a fork and [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "suggest an edit" link on any page of the docs.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [Erez Zukerman](https://github.com/ezuk), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official website

[http://qmk.fm](http://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
