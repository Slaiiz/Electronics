/* 
 * File:   libneopixels.h
 * Author: vchesnea
 *
 * Created on April 7, 2016, 12:54 PM
 */

#ifndef LIBNEOPIXELS_H
#define	LIBNEOPIXELS_H

#define F_CPU   8000000

typedef enum {
    RGB,
    GBR,
    BRG
} format;

void    neopixels_init(volatile unsigned int *latch, unsigned int pin);
void    neopixels_set(int led, char r, char g, char b);
void    neopixels_show(void);

#endif	/* LIBNEOPIXELS_H */
