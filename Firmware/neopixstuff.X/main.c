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

static long mode = 1;

unsigned int bcd_to_dec(unsigned long n)
{
    unsigned long   out;
    unsigned int    i;

    i = 1;
    out = 0;
    while (n) {
        out += (n & 15) * i;
        n >>= 4;
        i *= 10;
    }
    return (out);
}

void __attribute__((vector(_TIMER_1_VECTOR),interrupt(IPL1AUTO)))
     timer_tick(void)
{
    unsigned int            seconds;
    unsigned int            minutes;
    unsigned int            hours;
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
            seconds = bcd_to_dec((RTCTIME & 0x0000FF00) >> 8);
            minutes = bcd_to_dec((RTCTIME & 0x00FF0000) >> 16);
            hours   = bcd_to_dec((RTCTIME & 0xFF000000) >> 24);
            neopixels_clear();
            // Sectors
            for (i = 0; i < 60; i++) {
                if (!(i % 5))
                    neopixels_set(i, 20, 20, 0);
                else {
                    neopixels_set(i, 1, 1, 1);
                }
            }
            // Hours
            i = 60 - (60 * (hours % 12) / 12);
            neopixels_set((i - minutes / 12) % 60, 255, 0, 0);
            neopixels_set((i - 1 - minutes / 12) % 60, 30, 0, 0);
            neopixels_set((i + 1 - minutes / 12) % 60, 30, 0, 0);
            // Minutes
            i = 60 - minutes;
            neopixels_set(i % 60, 0, 255 * seconds / 59, 0);
            neopixels_set((i + 1) % 60, 0, 255 - 255 * seconds / 59, 0);
            // Seconds
            neopixels_set((60 - seconds) % 60, 0, 0, 255);
            neopixels_show();
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
            for (pixel = 0; pixel < 16; pixel++) {
                neopixels_set(pixel, ((seconds & i) && 1) * 255, 0, 0);
                i <<= 1;
            }
            seconds = (seconds + 1);
            neopixels_show();
            break ;
    }
    IFS0bits.T1IF = 0;
}

void __attribute__((vector(_EXTERNAL_1_VECTOR),interrupt(IPL2AUTO)))
     button_press(void)
{
    neopixels_clear();
    mode = (mode + 1) % 5;
    IFS0bits.INT1IF = 0;
}

void setup_callbacks(void)
{
    TMR1 = 0;
    PR1 = 32768;
    T1CONbits.TCKPS = 0;
    T1CONbits.TCS   = 1;
    T1CONbits.ON    = 1;
    INTCONbits.MVEC = 1;
    // Timer1
    IFS0bits.T1IF = 0;
    IPC1bits.T1IP = 1;
    IPC1bits.T1IS = 0;
    IEC0bits.T1IE = 1;
    // Button
    IFS0bits.INT1IF = 0;
    IPC1bits.INT1IP = 2;
    IPC1bits.INT1IS = 0;
    IEC0bits.INT1IE = 1;
    asm volatile("ei");
}

void configure_realtime_clock(void)
{
    RtccWrEnable(1);
    RTCCONbits.ON = 0;
    while (RTCCONbits.RTCCLKON);
    RTCTIME = 0x18515800;
    RTCCONbits.ON = 1;
    while (!RTCCONbits.RTCCLKON);
    RTCCONbits.RTCOE = 1;
    RtccWrEnable(0);
}

void main(void)
{
    SYSTEMConfigPerformance(8000000);
    TRISBbits.TRISB0 = 0;
    configure_realtime_clock();
    neopixels_init(&LATB, 0, 60);
    neopixels_clear();
    setup_callbacks();
    while (1);
}
