#include "liblcd.h"

void    liblcd_home(void)
{
    liblcd_command(LCD_RETURNHOME);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}