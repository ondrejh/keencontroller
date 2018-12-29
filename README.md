# Keen Controller
Arduino micro based keyboard (mame controller) suitable for playing [Commander Keen](http://www.shikadi.net/keenwiki/Main_Page).

![Final product look](/doc/keen_final.jpg)

## The challenge:
Commander Keen looks like very good game for simple "few buttons" controller. Arrows, jump, fire .. that should be it. Well, its not. There are alot of "hidden" keys you need when not additional keyboard is available (for example in mame box). Finally, when using only joystick and 10 buttons, there are still some limitations like shared keys or limited save possitions.

## Project status:
The project is basically finished. The alternative keymaps for other games were added, multiple key was implemented, key sharing by rotating, ect.

- button model (learning freecad)
- all possible inputs of arduino covered now
- basic arduino program with 3 keys
- commander keen keymap
- wooden body
- dangerous dave and prince 2 keymaps

## BOM:

- [Arduino micro ATmega32U4](https://www.aliexpress.com/item/Free-Shipping-New-Pro-Micro-for-arduino-ATmega32U4-5V-16MHz-Module-with-2-row-pin-header/1348800135.html?spm=2114.search0104.3.1.65653ecf7knLvI&ws_ab_test=searchweb0_0,searchweb201602_5_10065_10068_319_317_10696_10084_453_454_10083_10618_10304_10307_10820_10821_538_537_10302_536_10059_10884_10887_100031_321_322_10103,searchweb201603_53,ppcSwitch_0&algo_expid=e6bf0f1d-14d2-4c70-9fee-68fe26168dd5-0&algo_pvid=e6bf0f1d-14d2-4c70-9fee-68fe26168dd5) ![Arduino Leonardo Pro Micro](/doc/arduino.jpg)
- [10pcs 24mm arcade buttons](https://www.aliexpress.com/item/10-pcs-factory-price-arcade-button-24mm-Round-Push-Button-Built-in-small-micro-switch-for/32881608601.html?spm=a2g0s.9042311.0.0.7df04c4dFhE223) ![24mm button](/doc/button.jpg)
- [Arcade joystick](https://www.aliexpress.com/item/Classic-Arcade-Joystick-4-8-way-DIY-Game-Joystick-Red-Ball-Fighting-Stick-Replacement-Parts-For/32571616716.html?spm=a2g0s.9042311.0.0.7df04c4dFhE223) ![Joystick](/doc/joystick.jpg)
- Wood, glue, screws and resin
- Wires and solder

## Schematic (wire mess sketched on touchpad):

![Schematic](/doc/wire_mess.jpg)

## Keys needed (Commander Keen 1-3 / 4-6)
Arrows, ctrl, alt, esc, 1 - 9 (or at least some of those), y/t, n/d/enter ...

## Next steps:

1) Implement multiple keypress by queue (still not work).
2) Model (learn freecad, better).
3) Automatic keymap change (with some gui).

## Guts, if youre interested:

![How it looks inside](/doc/keen_guts.jpg)

