/*
 * File:   bcd.c
 * Author: vchesnea
 *
 * Created on April 16, 2016, 2:39 PM
 */

//#include "rainbowclock.h"

unsigned long bcd_to_dec(unsigned long n)
{
    unsigned long   out;
    unsigned int    i;

    i = 1;
    out = 0;
    while (n) {
        out += (n & 15) * i;
        n >>= 4;
        i *= 10;
    }
    return (out);
}
