#include "lcd.h"

void    LCD_pulseE(void)
{
    LATEbits.LATE7 = 0;
    delay_micros(1); //1
    LATEbits.LATE7 = 1;
    delay_micros(1); //1
    LATEbits.LATE7 = 0;
    delay_micros(100); //100
}