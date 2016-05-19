/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 28, 2016, 11:19 AM
 */

#include "types.h"
#include "confbits.h"

void main(void)
{
    u8  obutton;
    u8  nbutton;

    obutton = ~0;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        nbutton = PORTDbits.RD8;
        if (!nbutton && obutton)        // You don't want any repeats
            LATFbits.LATF1 ^= 1;
        obutton = nbutton;              // Latch the button in memory
    }
}
