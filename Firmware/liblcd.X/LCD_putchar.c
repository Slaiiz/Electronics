#include "lcd.h"

void    LCD_putchar(UINT8 car)
{
    LCD_send(car, 1);
    _curcol++;
}