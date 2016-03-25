/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 25, 2016, 5:11 PM
 */

#include <xc.h>
#include <sys/attribs.h> // This unlocks the __ISR macro
#include "types.h"

void    __ISR(_TIMER_1_VECTOR, ipl2) toggle_led(void)
{
    _RF1 ^= 1;
}

void    setup_timer(void)
{
    // The timer shall be enabled
    T1CONbits.ON = 1;
    // It is also internal
    T1CONbits.TCS = 0;
    // And has a ratio of 1:1
    T1CONbits.TCKPS = 0;
}

void    setup_interrupts(void)
{
    INTCON = 0; // completely wipe-out possible residual data
    IEC0bits.T1IE = 1; // Timer1 Interrupt Enabled
}

void    clear_watchdog(void)
{
    WDTCONbits.WDTCLR = 1;
}

int     main(void)
{
    _TRISF1 = 0;
    setup_timer();
    setup_interrupts();
    while (1) {
        clear_watchdog(); // a better alternative would be the ClearWDT() macro
        // do stuff ...
    }
    return (0);
}
