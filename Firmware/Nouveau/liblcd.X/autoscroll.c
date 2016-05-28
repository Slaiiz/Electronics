#include "liblcd.h"

void    liblcd_autoscroll(bool on) {
    if (on == true)
        _displaymode |= LCD_ENTRYSHIFTINCREMENT;
    else
        _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
    liblcd_command(LCD_ENTRYMODESET | _displaymode);
}