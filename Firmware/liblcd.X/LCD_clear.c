#include "lcd.h"

void    LCD_clear(void)
{
    LCD_command(LCD_CLEARDISPLAY);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}