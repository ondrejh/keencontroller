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

## Keys needed (Commander Keen 1-3 / 4-6)
Arrows, ctrl, alt, esc, 1 - 9 (or at least some of those), y/t, n/d/enter ...

## Next steps:

1) Implement multiple keypress by queue (still not work).
2) Model (learn freecad, better).
3) Automatic keymap change (with some gui).

## Guts, if youre interested:

![How it looks inside](/doc/keen_guts.jpg)

