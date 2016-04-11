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
    TRISBCLR = 32;
    neopixels_init(&LATB, 5);
    neopixels_set(0, 255, 0, 0);
    while (1)
        neopixels_show();
}
