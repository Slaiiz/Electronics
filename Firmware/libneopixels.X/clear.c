/*
 * File:   clear.c
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

void    libneopixels_clear(void)
{
    UINT32  nleds;

    nleds = _nleds;
    while (nleds)
        libneopixels_set(--nleds, 0, 0, 0);
}

