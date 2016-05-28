#include "liblcd.h"

void    liblcd_display(bool on)
{
    if (on == true)
        _displaycontrol |= LCD_DISPLAYON;
    else
        _displaycontrol &= ~LCD_DISPLAYON;
    liblcd_command(LCD_DISPLAYCONTROL | _displaycontrol);
}