#include "liblcd.h"

void    liblcd_cursor(bool on) {
    if (on == true)
        _displaycontrol |= LCD_CURSORON;
    else
        _displaycontrol &= ~LCD_CURSORON;
    liblcd_command(LCD_DISPLAYCONTROL | _displaycontrol);
}