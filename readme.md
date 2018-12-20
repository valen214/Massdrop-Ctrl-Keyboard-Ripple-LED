# Massdrop CTRL Keyboard Splash LED

adding LED Splash effect with the provided QMK software.

demo video: https://youtu.be/W3U1SDztx1I

feel free to leave comments or feature request.

## How to use:
### Build yourself
1) have everything set up (to a point where you can compile and flash driver)
2) `make massdrop/ctrl:custom`
3) `./.build/mdloader_windows.exe --first --download massdrop_ctrl_custom.bin --restart`
(I am sorry that I am using MSYS)
4) `Fn + B` or use the pin to reset
5) Done

### qmk toolbox
1) bin file inside /.build/

fullstop.

## (Currently Available) Settings

### Key Combos:

- `Hold(Fn + P) + A`, `Hold(Fn + P) + D`: Previous/Next dripple effect 
  - 0: None
  - 1: background off wave on (default)
  - 2: background on wave off
  - 3: rainbow wave :rainbow:
  - 4: rainbow wave on rotate background

- `Hold(Fn + P) + W`, `Hold(Fn + P) + S`: Increase/Decrease dripple wave width (default: 2, 10 on rainbow and 5 on wave off, set to >10 and press space to see true rainbow!)

- `Hold(Fn + P) + Q`, `Hold(Fn + P) + E`: Decrease/Increase wave speed (actually it's wave period, default: 30~50ms, 10ms per incre/decre, lowest(fastest): 10ms)

- `Hold(Fn) + Up`, `Hold(Fn) + Down`: scroll up and down (implemented with MOUSEKEY, because page up/down scrolls too fast)

`UIO` are equivalent to `QWE` (the keys will light up after pressing `Fn + P`

`JKL` are equivalent to `ASD` so as to allow one hand switching

### TODO:

- add indicator

- check out the functions from `https://beta.docs.qmk.fm/features/feature_rgblight`

## Implementation:
**basically all changes happen only in `/keyboards/massdrop/ctrl/keymaps/custom/keymap.c`:**
Inspired by [LastContinue's Post](https://www.massdrop.com/talk/9382/how-to-configure-your-ctrl-keyboard/2201429),
by abusing `led_instructions_t` to set the led of each individual key only in `keymap.c` (It is understood to be very inefficient, but one benefit of this is being more prone to future changes (if any, ok I know there is very little) and slightly more portable (more below)).

one core function is `unsigned char ktli(uint16_t keycode);`
where you input the keycode to return the id of the led light that key correspond to (as mentioned in the post).
Therefore, ideally, changing this function alone is enough to use the code on other QMK 87 keyboards (assumption is made that the parent project from massdrop is identical to QMK's, but that's not true, I am unable to compile the code with QMK's firmware fork, didn't bother to debug).

another core function is `matrix_scan_user()`
This is provided in the specification. This function is invoked after every
small period, to check the time passed after a key press registered as in
`process_record_user(keycode)` (which stores information in `KEY_STROKES`),
against the distance between the registered key and the targeted led key.

The `DISTANCE_MAP[][]` (as initialized from `matrix_init_user()`)
recorded the distances (adjacent key as 1 unit) between each of the two keys.
While additional algorithm is used to calibrate the distance between two keys
which appears to be distinct in a 2D array, but adjacent in reality. (
This process could have been cached before compiling)


## Known bugs/limitations
~~- double click a key will reset the original "wave front"~~

~~- not really appealing when typing in a fast speed (I don't have a led keyboards that have splashing so I don't know what the effect should have looked like. I am just doing this by imagination.~~ # It is easy to add limit to distance traveled by the light, I would try if it has any positive effect)

~~function keys (F1 - F12) and navigation keys (Ins, Home) are not working. (funtion keys are little bit tricky, but navigation keys are~~ => easily implemented by updating `KEY_POSITION_MAP`)

- F1 to F4 will light up on the same time after pressing LCTRL, F9 to F12 will do also after pressing RCTRL (it is more or less correct in theory)


This project is just for fun and please don't be serious :blush:.


## What's different (or added) from the forked project: (root as project folder)
`+ /hid_listen.exe`

`+ /massdrop_ctrl_default.bin`

`+ /massdrop_ctrl_custom.bin`

`+ /massdrop_ctrl_custom_activate_on_press.bin`

`+ /mdloader_linux`

`+ /mdloader_windows.exe`

`+ /qmktoolbox.exe`

`+ /.build/*`

`+ /keyboards/massdrop/ctrl/keymaps/custom/*`

`+ /keyboards/massdrop/ctrl/keymaps/custom_activate_on_press/*`

`! /keyboards/massdrop/ctrl/keymaps/config.h` # adding parameters for MOUSEKEY

`! /keyboards/massdrop/ctrl/keymaps/rules.mk` # changing MOUSEKEY_ENABLE = yes


other changes are unintentional or not important.


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
