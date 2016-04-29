/*
 * File:   libneopixels.h
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#ifndef LIBNEOPIXELS_H
#define	LIBNEOPIXELS_H

#include <GenericTypeDefs.h>

typedef enum {
    RGB,
    GBR,
    BRG
} format;

void    libneopixels_begin(volatile UINT16* port, UINT8 pin, UINT32 numleds);
void    libneopixels_set(UINT32 led, UINT8 r, UINT8 g, UINT8 b);
void    libneopixels_clear(void);
void    libneopixels_show(void);

extern UINT32    _leds[60];
extern UINT16*  _latch;
extern UINT32   _nleds;
extern UINT8    _pin;

#endif
