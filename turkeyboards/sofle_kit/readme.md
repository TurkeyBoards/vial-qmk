# Sofle Choc Kit

*A short description of the keyboard/project*

* Keyboard Maintainer: [turkeyboards](https://github.com/turkeyboards)
* Hardware Supported: RP2040
* Hardware Availability: [Turkeyboards Shop](https://turkeyboards.com/products/sofle-rgb-low-profile) or [Sofle Build Guide](https://github.com/josefadamcik/SofleKeyboard/blob/master/docs/build_guide_choc.md)


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available


## Compile Keyboard
* qmk clean
* qmk compile -kb turkeyboards/sofle_kit/v1 -km vial

## Update For New Keyboards
* qmk list-keyboards