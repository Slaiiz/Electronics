/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include <xc.h>
#include <plib.h>
#include "confbits.h"
#include "libneopixels.h"

static long mode;

void    __attribute__((vector(_TIMER_2_VECTOR),interrupt(IPL1AUTO)))
        timer_tick(void)
{
    static unsigned int     seconds;
    static unsigned int     minutes;
    static unsigned int     hours;
    static unsigned int     pixel;
    int                     i;

    switch (mode) {
        case 0:
            neopixels_set(pixel + 0, 0, 0, 0);
            neopixels_set((pixel + 1) % 60, 28, 0, 0);
            neopixels_set((pixel + 2) % 60, 0, 90, 0);
            neopixels_set((pixel + 3) % 60, 0, 0, 28);
            neopixels_set((pixel + 4) % 60, 0, 0, 0);
            pixel = (pixel + 1) % 60;
            neopixels_show();
            break ;
        case 1:
            neopixels_clear();
            // Quadrants
            for (i = 0; i < 60; i += 5)
                neopixels_set(i, 20, 20, 0);
            // Hours
            neopixels_set((60 * hours / 12 + minutes / 12), 255, 0, 0);
            neopixels_set((60 * hours / 12 - 1 + minutes / 12) % 60, 30, 0, 0);
            neopixels_set((60 * hours / 12 + 1 + minutes / 12) % 60, 30, 0, 0);
            // Minutes
            neopixels_set((60 * minutes / 60 + 1) % 60, 0, 255 * seconds / 60, 0);
            neopixels_set((60 * minutes / 60), 0, 255 - (255 * seconds / 60), 0);
            // Seconds
            neopixels_set((60 * seconds / 60), 0, 0, 255);
            neopixels_show();
            seconds = (seconds + 1) % 60;
            if (!seconds) {
                minutes = (minutes + 1) % 60;
                if (!minutes) {
                    hours = (hours + 1) % 24;
                }
            }
            break ;
        case 2:
            for (pixel = 0; pixel < 60; pixel++) {
                neopixels_set(pixel, 0, 255 * (pixel + i) / 60, 0);
            }
            neopixels_show();
            i = (i + 1) % 60;
            break ;
        case 3:
            for (pixel = 0; pixel < 60; pixel++) {
                neopixels_set(pixel, seconds, seconds, seconds);
            }
            seconds = (seconds + 1) % 255;
            neopixels_show();
            break ;
        case 4:
            i = 1;
            for (pixel = 0; pixel < 8; pixel++) {
                neopixels_set(pixel, ((seconds & i) && 1) * 255, 0, 0);
                i <<= 1;
            }
            seconds = (seconds + 1) & 255;
            neopixels_show();
            break ;
    }
    IFS0bits.T2IF = 0;
}

void    __attribute__((vector(_EXTERNAL_1_VECTOR),interrupt(IPL2AUTO)))
        button_press(void)
{
    neopixels_clear();
    mode = (mode + 1) % 5;
    IFS0bits.INT1IF = 0;
}

void    setup_callbacks(void)
{
    TMR2 = 0;
    PR2 = F_CPU / 256 / 30;
    T2CONbits.TCKPS = 0b111;
    T2CONbits.ON = 1;
    INTCONbits.MVEC = 1;
    // Timer2
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 1;
    IPC2bits.T2IS = 0;
    IEC0bits.T2IE = 1;
    // Button
    IFS0bits.INT1IF = 0;
    IPC1bits.INT1IP = 2;
    IPC1bits.INT1IS = 0;
    IEC0bits.INT1IE = 1;
    asm volatile("ei");
}

void    main(void)
{
    SYSTEMConfigPerformance(8000000);
    TRISBbits.TRISB0 = 0;
    neopixels_init(&LATB, 0, 60);
    neopixels_clear();
    setup_callbacks();
    while (1);
}
