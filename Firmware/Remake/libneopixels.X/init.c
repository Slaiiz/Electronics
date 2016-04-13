/*
 * File:   init.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#include "libneopixels.h"

long    _leds[8];
int     *_latch;
long    _nleds;
char    _pin;

/*
 * Example : neopixels_init(&LATF, 1);
 */

void    neopixels_init(volatile unsigned int *port, char pin, long numleds)
{
    _latch = (int*)port;
    _nleds = numleds;
    _pin = pin;
}
