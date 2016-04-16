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

long    _leds[60];
int     *_latch;
long    _nleds;
char    _pin;

/*
 * Example : neopixels_begin(&LATF, 1, 60);
 */

void    neopixels_begin(volatile unsigned int *port, char pin, long numleds)
{
    _latch = (int*)port;
    _nleds = numleds;
    _pin = pin;
}
