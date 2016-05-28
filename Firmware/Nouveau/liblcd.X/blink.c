#include "liblcd.h"

void    liblcd_blink(bool on) {
    if (on == true)
        _displaycontrol |= LCD_BLINKON;
    else
        _displaycontrol &= ~LCD_BLINKON;
    liblcd_command(LCD_DISPLAYCONTROL | _displaycontrol);
}