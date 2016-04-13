/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include <xc.h>
#include <plib.h>
#include "libneopixels.h"

void    main(void)
{
    SYSTEMConfigPerformance(8000000);
    TRISBbits.TRISB0 = 0;
    neopixels_init(&LATB, 0, 8);
    neopixels_set(0, 255, 0, 0);
    neopixels_set(1, 0, 0, 0);
    neopixels_set(2, 255, 0, 0);
    neopixels_set(3, 0, 0, 0);
    neopixels_set(4, 255, 0, 0);
    neopixels_set(5, 0, 0, 0);
    neopixels_set(6, 255, 0, 0);
    neopixels_set(7, 0, 0, 0);
    neopixels_show();
}
