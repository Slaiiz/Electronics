/*
 * File:   begin.c
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

UINT8   _leds[60];
UINT32* _latch;
UINT32  _nleds;
UINT8   _pin;

/*
 * Example : neopixels_begin(&LATF, 1, 60);
 */

void    libneopixels_begin(volatile UINT8* port, UINT8 pin, UINT32 numleds)
{
    _nleds = numleds;
    _latch = port;
    _pin = pin;
}
