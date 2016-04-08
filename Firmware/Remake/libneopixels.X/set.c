/*
 * File:   set.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

extern unsigned int     _leds[2];
extern unsigned int     *_latch;
extern unsigned char    _pin;

void    neopixels_set(char led, char r, char g, char b)
{
    _leds[led] = (r << 0) + (g << 8) + (b << 16);
}
