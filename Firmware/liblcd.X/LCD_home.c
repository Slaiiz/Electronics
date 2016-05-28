#include "lcd.h"

void    LCD_home(void)
{
    LCD_command(LCD_RETURNHOME);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}