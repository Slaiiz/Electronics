/*
 * File:   set.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

void    neopixels_set(char led, unsigned char r, unsigned char g, unsigned char b)
{
    _leds[led] = (g << 0) | (r << 8) | (b << 16);
}
