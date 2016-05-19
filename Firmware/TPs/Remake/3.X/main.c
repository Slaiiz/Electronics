/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 28, 2016, 11:19 AM
 */

#include "types.h"
#include "confbits.h"

#define F_CPU       8000000L
#define F_PERIOD    (F_CPU) / 256       //  Timer clocks in one second
                                        //  Divided by the prescaler

u16 period = F_PERIOD;

void setup_timer(void)
{
    T2CONbits.TCKPS = 0b111;            // 1:256 Prescaler
    T2CONbits.ON = 1;                   // Enable Timer2
    PR2 = 65535;                        // 16-bit Period
}

void setup_interrupts(void)
{
    
}

void clear_watchdog(void)
{
    WDTCONbits.WDTCLR = 1;
}

void main(void)
{
    setup_timer();
    setup_interrupts();
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1)
        clear_watchdog();
}
