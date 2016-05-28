#include "lcd.h"

void    LCD_putstr(UINT8 *str)
{
    UINT32 i;
    i = 0;
    while (str[i] && (i < (_numcol * _numrow)))
    {
        if ((_curcol >= _numcol || str[i] == '\n'))
        {
            if (_currow < _numrow)
                LCD_setCursor(0, _currow + 1);
            if (str[i] == '\n')
                i++;
        }
        LCD_putchar(str[i]);
        i++;
    }
}