#include "liblcd.h"

void    liblcd_clear(void)
{
    liblcd_command(LCD_CLEARDISPLAY);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}