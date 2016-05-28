#include "liblcd.h"

void    liblcd_send(UINT8 value, UINT8 mode)
{
    LATDbits.LATD4  = (value >> 0) & 1;
    LATDbits.LATD5  = (value >> 1) & 1;
    LATDbits.LATD6  = (value >> 2) & 1;
    LATDbits.LATD7  = (value >> 3) & 1;
    LATDbits.LATD10 = (value >> 4) & 1;
    LATDbits.LATD11 = (value >> 5) & 1;
    LATEbits.LATE0  = (value >> 6) & 1;
    LATEbits.LATE3  = (value >> 7) & 1;
    LATEbits.LATE6  = mode;
    liblcd_pulse();
}
