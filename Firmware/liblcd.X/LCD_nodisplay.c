#include "lcd.h"

void    LCD_nodisplay(void)
{
    _displaycontrol &= ~LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}