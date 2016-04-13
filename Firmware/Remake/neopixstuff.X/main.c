/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include <xc.h>
#include <plib.h>
#include "libneopixels.h"

void    __attribute__((vector(_EXTERNAL_1_VECTOR),interrupt(IPL1AUTO)))
        button_press(void)
{
    static char flip;

    neopixels_set(flip, 255, 0, 0);
    flip = (flip % 60) + 1;
    neopixels_show();
    IFS0bits.INT1IF = 0;
}

void    setup_interrupts(void)
{
    INTCONbits.MVEC = 1;
    IFS0bits.INT1IF = 0;
    IPC1bits.INT1IP = 1;
    IPC1bits.INT1IS = 0;
    IEC0bits.INT1IE = 1;
    asm volatile("ei");
}

void    main(void)
{
    SYSTEMConfigPerformance(8000000);
    TRISBbits.TRISB0 = 0;
    neopixels_init(&LATB, 0, 60);
    neopixels_show();
    setup_interrupts();
    while (1);
}
