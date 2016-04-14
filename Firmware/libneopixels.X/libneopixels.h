/*
 * File:   libneopixels.h
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#ifndef LIBNEOPIXELS_H
#define	LIBNEOPIXELS_H

typedef enum {
    RGB,
    GBR,
    BRG
} format;

void    neopixels_init(volatile unsigned int *port, char pin, long numleds);
void    neopixels_set(char led, unsigned char r, unsigned char g, unsigned char b);
void    neopixels_clear(void);
void    neopixels_show(void);

extern long _leds[60];
extern int  *_latch;
extern long _nleds;
extern char _pin;

#endif	/* LIBNEOPIXELS_H */
