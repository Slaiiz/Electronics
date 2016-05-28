#include "libserial.h"

void    delay_micros(UINT32 micros)
{
    while (micros--);
}

void    delay_millis(UINT32 millis)
{
    while (millis--)
        delay_micros(1000);
}
