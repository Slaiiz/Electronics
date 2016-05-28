#include "lcd.h"

void    LCD_putstrPos(UINT8 *str, UINT8 col, UINT8 row)
{
    LCD_setCursor(col, row);
    LCD_putstr(str);
}