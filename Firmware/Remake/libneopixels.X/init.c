/*
 * File:   init.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

unsigned int _leds[60];
unsigned int *_latch;
unsigned int _pin;

/*
 * Example : neopixels_init(&LATF, 1);
 */

void    neopixels_init(volatile unsigned int *latch, unsigned int pin)
{
    _latch = (unsigned int*)latch;
    _pin = pin;
}
