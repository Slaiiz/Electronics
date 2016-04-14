/*
 * File:   set.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

/*
 * Notice:
 * 
 * This library was designed for the PIC32MX340F512H microcontroller for a
 * clock freqency of 8MHz. Its successful use on other devices is not
 * guaranteed.
 */

#include "libneopixels.h"

void    neopixels_set(char led, unsigned char r, unsigned char g, unsigned char b)
{
    _leds[led] = (b << 8) | (r << 16) | (g << 24);
}
