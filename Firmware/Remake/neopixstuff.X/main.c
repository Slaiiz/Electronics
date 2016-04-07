/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include <xc.h>
#include "libneopixels.h"

void main(void)
{
    TRISBCLR = 1;
    neopixels_init(&LATB, 0);
    neopixels_set(0, 255, 0, 0);
    neopixels_show();
    neopixels_set(0, 0, 255, 0);
    neopixels_show();
}
