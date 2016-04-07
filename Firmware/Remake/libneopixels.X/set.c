/*
 * File:   set.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

extern unsigned int _leds[60];
extern unsigned int *_latch;
extern unsigned int _pin;

void    neopixels_set(int led, char r, char g, char b)
{
    _leds[led] = (r << 0) + (g << 8) + (b << 16);
}
