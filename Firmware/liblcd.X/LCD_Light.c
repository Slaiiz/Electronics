#include "lcd.h"

void    LCD_Light(UINT8 mode)
{
    LATFbits.LATF5 = mode;
}