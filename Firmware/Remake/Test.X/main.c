/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on March 28, 2016, 6:03 PM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "configbits.h"

void __ISR(_TIMER_2_VECTOR, IPL2AUTO) LedBlink (void)
{
    LATFbits.LATF1 ^= 1;
    IFS0bits.T2IF = 0;
}

void setup_timer(void)
{
    T2CONbits.TCKPS = 0;
    T2CONbits.ON = 1;
    PR2 = 4095;
}

void setup_interrupt(void)
{
    IPC2bits.T2IP = 2;
    IEC0bits.T2IE = 1;
    INTEnableInterrupts();
}

void clear_watchdog(void)
{
    WDTCONbits.WDTCLR = 1;
}

void main(void)
{
    setup_timer();
    setup_interrupt();
    while (1) {
        clear_watchdog();
    }
}
