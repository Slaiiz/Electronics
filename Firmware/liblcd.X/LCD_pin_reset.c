#include "lcd.h"

void    LCD_pin_reset(void)
{
    TRISF   = 0;
    TRISD   = 0;
    LATD    = 0;
    TRISE   = 0;
    LATE    = 0;
}
