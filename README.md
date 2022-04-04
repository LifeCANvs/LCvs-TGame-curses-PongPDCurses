# PongPDCurses

Pong written using PDCurses.

## Dependencies

* PDCurses [Github](https://github.com/wmcbrine/PDCurses)

## Static compilation

CodeBlocks:

Build options -> Other linker options -> "-l:pdcurses.a"

Or rename "pdcurses.a" to "libpdcurses.a" then you can specify "pdcurses" in "Link libraries".

Apply the "-static" flag in the compiler settings.
