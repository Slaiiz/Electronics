/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 29, 2016, 11:48 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "types.h"
#include "confbits.h"

#define F_CPU    8000000L
#define F_PERIOD (F_CPU) / 256  // Divided by the prescale ratio

u8  mode;

void __ISR(_TIMER_1_VECTOR, IPL3AUTO) mode_switch(void)
{
    if (!PORTDbits.RD8)                 // Still holdin' the button yet ... ?
    {
        mode ^= 1;                      // ... Ok switch to the other mode
        if (mode) {                     // Got into second mode ... ?
            T2CONbits.TCKPS = 0b000;    // ... Then we need the best resolution for pwm
            PR2 = 65535;                // ... Which means we have to do that too
            OC1CONbits.ON = 1;          // ... Turn on PWM
            IEC0bits.T2IE   = 0;
        } else {                        // Got back into first mode ... ?
            OC1CONbits.ON = 0;          // ... Then turn off PWM
            T2CONbits.TCKPS = 0b111;    // ... Reset prescaler to its former value
            PR2             = F_PERIOD; // ... Sames goes for the period register
            IEC0bits.T2IE   = 1;
        }
    }
    T1CONbits.ON = 0;           // Turn off Timer1
    IFS0bits.T1IF = 0;          // Clear the interrupt flag upon leaving
}

void __ISR(_TIMER_2_VECTOR, IPL2AUTO) mode_led_blink(void)
{
    LATFbits.LATF1 ^= 1;    // Toggle the LED
    IFS0bits.T2IF = 0;
}

void __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL2AUTO) mode_led_pwm(void)
{
    OC1RS = (OC1RS + 1) & 65535;
    IFS0bits.OC1IF = 0;
}

void __ISR(_EXTERNAL_1_VECTOR, IPL4AUTO) button_press(void)
{
    PR2 /= 2;                   // Divide period by 2, multiplying speed by 2
    TMR2 = 0;                   // Reset Timer2, Don't leave it half-filled
    if (PR2 < F_PERIOD / 16)    // Got through all the five states ... ?
        PR2 = F_PERIOD;         // ... Then go back to the first
    T1CONbits.ON = 1;           // Start Timer1 since we pressed the button
    TMR1 = 0;                   // But also prevent the user from cheating
    IFS0bits.INT1IF = 0;
}

void setup_timers(void)
{
    // Timer1
    PR1 = 65535;                // 32768Hz oscillator, means PR1 is reached
                                // in 2 seconds
    T1CONbits.TCS = 1;          // Timer1 should pump clocks from the slower RTC
    // Timer2
    PR2 = F_PERIOD;             // At this point, F_PERIOD clocks equal 0.5Hz
    T2CONbits.TCKPS = 0b111;    // Give Timer2 a 1:256 prescaler ratio
    T2CONbits.ON = 1;           // Enable Timer2
    // Output Compare 1
}

void setup_interrupts(void)
{
    INTCONbits.MVEC = 1;        // Multi-vector mode ON
    // Timer1
    IFS0bits.T1IF = 0;          // Clear Timer1's interrupt flag, just in case
    IPC1bits.T1IP = 3;          // Timer1's interrupt vector has a priority of 3
    IPC1bits.T1IS = 0;          // And a subpriority of 0
    IEC0bits.T1IE = 1;          // Enable it
    // Timer2
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 2;
    IPC2bits.T2IS = 0;
    IEC0bits.T2IE = 1;
    // Button
    IFS0bits.INT1IF = 0;
    IPC1bits.INT1IP = 4;
    IPC1bits.INT1IS = 0;
    IEC0bits.INT1IE = 1;
    // Output compare
    OC1R              = 0;      // Set master register's duty-cycle to 0%
    OC1RS             = 0;      // Do the same for the slave register
    OC1CONbits.OCTSEL = 0;      // We want to use Timer2 as the Output Compare
    OC1CONbits.OCM    = 0b111;  // PWM Mode w/o fault pin, OC1R is now read-only
    IEC0bits.OC1IE    = 1;
}

void clear_watchdog(void)
{
    WDTCONbits.WDTCLR = 1;      // Self-explanatory, prevent the watchdog from
                                // causing a hardware reset
}

void main(void)
{
    setup_timers();
    setup_interrupts();
    TRISFbits.TRISF1 = 0;       // Register F1 is an output
    TRISDbits.TRISD8 = 1;       // Register D8 is an input
    INTEnableInterrupts();      // Stop ignoring interrupts
    while (1) {
        clear_watchdog();
    }
}
