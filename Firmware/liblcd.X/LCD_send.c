#include "lcd.h"

void    LCD_send(UINT8 value, UINT8 mode)
{
    LCD_pin_reset();
    LATEbits.LATE6      = mode;
    LATDbits.LATD4     = (value % 2);
    value /= 2;
    LATDbits.LATD5     = (value % 2);
    value /= 2;
    LATDbits.LATD6     = (value % 2);
    value /= 2;
    LATDbits.LATD7     = (value % 2);
    value /= 2;
    LATDbits.LATD10     = (value % 2);
    value /= 2;
    LATDbits.LATD11     = (value % 2);
    value /= 2;
    LATEbits.LATE0      = (value % 2);
    value /= 2;
    LATEbits.LATE3      = (value % 2);
    LCD_pulseE();
}