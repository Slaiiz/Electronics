/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 25, 2016, 5:11 PM
 */

#include <xc.h>
#include <sys/attribs.h> // This unlocks the __ISR macro

#include "types.h"

void __ISR(_TIMER_1_VECTOR, IPL2AUTO) Timer1Handler(void)
{
    _LATF1 ^= 1;
    IFS0bits.T1IF = 0; // clear Timer1's interrupt flag, otherwise it might
                       // be retriggered upon leaving the ISR
}

void __ISR(_EXTERNAL_1_VECTOR, IPL3AUTO) ButtonHandler(void)
{
    PR1 /= 2;
    if (PR1 < 4096)
        PR1 = 65535;
    IFS0bits.INT1IF = 0;
}

/* Same as above if you don't want to use __ISR
 __attribute__((vector(_TIMER_1_VECTOR), interrupt(IPL2AUTO), nomips16))
 void Timer1Handler(void)
 {
    _LATF1 ^= 1;
    IFS0bits.T1IF = 0; // clear Timer1's interrupt flag, otherwise it might
                       // be retriggered upon leaving the ISR
 }
 */

void setup_timer(void)
{
    // The timer is internal
    T1CONbits.TCS = 0;
    // it has a ratio of 1:1
    T1CONbits.TCKPS = 0;
    // and it shall be enabled
    T1CONbits.ON = 1;
    // Set Timer1's period to 65535
    PR1 = 65535;
}

void setup_interrupts(void)
{
    INTCON = 0; // completely wipe-out possible residual data
    INTCONbits.MVEC = 1; // enable multi-vector mode
    IFS0bits.T1IF = 0; // clear Timer1's interrupt flag ... just in case
    IPC1bits.T1IP = 2; // Timer1 Interrupt Priority
    IPC1bits.T1IS = 0; // Timer1 Interrupt Subpriority
    IEC0bits.T1IE = 1; // Timer1 Interrupt Enabled

    IFS0bits.INT1IF = 0; // clear Timer1's interrupt flag ... just in case
    IPC1bits.INT1IP = 3; // Button1 Interrupt Priority
    IPC1bits.INT1IS = 0; // Button1 Interrupt Subpriority
    IEC0bits.INT1IE = 1; // Button1 Interrupt Enabled
}

void clear_watchdog(void)
{
    WDTCONbits.WDTCLR = 1;
}

int main(void)
{
    setup_timer();
    setup_interrupts();
    asm volatile("ei"); // May also use INTEnableInterrupts() macro
    _TRISF1 = 0;
    while (1) {
        // clear_watchdog(); // a better alternative would be the ClearWDT() macro
        // do stuff ...
    }
    return (0);
}
