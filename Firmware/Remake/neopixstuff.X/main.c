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

    flip <<= 1;
    flip |= !flip;
    neopixels_set(0, ((flip & 1) >> 0) * 255, 0, 0);
    neopixels_set(1, ((flip & 2) >> 1) * 255, 0, 0);
    neopixels_set(2, ((flip & 4) >> 2) * 255, 0, 0);
    neopixels_set(3, ((flip & 8) >> 3) * 255, 0, 0);
    neopixels_set(4, ((flip & 16) >> 4) * 255, 0, 0);
    neopixels_set(5, ((flip & 32) >> 5) * 255, 0, 0);
    neopixels_set(6, ((flip & 64) >> 6) * 255, 0, 0);
    neopixels_set(7, ((flip & 128) >> 7) * 255, 0, 0);
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
    setup_interrupts();
    while (1);
}
