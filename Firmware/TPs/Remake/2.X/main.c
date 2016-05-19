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

void setup_timer(void)
{
    T2CONbits.TCKPS = 0b111;            // 1:256 Prescaler
    T2CONbits.ON = 1;                   // Enable Timer2
    PR2 = 0xffff;                       // 16-bit Period
}

void main(void)
{
    u16 period;
    u8  obutton;
    u8  nbutton;

    setup_timer();
    obutton = ~0;
    period = F_PERIOD;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR2 > period) {            // Did we
            LATFbits.LATF1 ^= 1;        // ... Then toggle the status LED
            TMR2 = 0;
        }
        nbutton = PORTDbits.RD8;
        if (!nbutton && obutton) {      // You don't want any repeats
            period /= 2;                // Make the LED blink twice as fast
            if (period < F_PERIOD / 16) // 16 = 2^(numstates-1) = 2^(5-1)
                period = F_PERIOD;      // Reached the fifth state, now reset
        }
        obutton = nbutton;              // Latch the button in memory
    }
}
