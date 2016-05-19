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
 * clock frequency of 8MHz. Its successful use on other devices is not
 * guaranteed.
 */

#include "libneopixels.h"

void    libneopixels_set(UINT32 led, UINT8 r, UINT8 g, UINT8 b)
{
    _leds[led] = ((UINT32)b << 8) | ((UINT32)r << 16) | ((UINT32)g << 24);
}
