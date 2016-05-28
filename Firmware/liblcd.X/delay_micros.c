#include "lcd.h"

void    delay_micros(UINT32 ms)
{
    while (ms)
    {
        ms--;
    }
}