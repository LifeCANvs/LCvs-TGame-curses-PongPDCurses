# PongPDCurses

Pong in console, written in C++ using PDCurses.

![Pong](https://github.com/wak-sudo/PongPDCurses/blob/main/screenshots/Pong.png)

## Controls

**W** & **S** for player no. 1.

**I** & **K** for player no. 2.

## How to build

Build using Code::Blocks and .cbp file.

### Dependencies

Should be put in the "libs" folder.

* PDCurses [Github](https://github.com/wmcbrine/PDCurses)

### Static compilation

*Code::Blocks:*
```
Build options -> Other linker options -> "-l:pdcurses.a"

Or rename "pdcurses.a" to "libpdcurses.a" then you can specify "pdcurses" in "Link libraries".

Apply the "-static" flag in the compiler settings.
```
