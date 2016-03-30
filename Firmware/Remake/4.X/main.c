/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on March 29, 2016, 11:48 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "confbits.h"

#define F_CPU       8000000L
#define F_PERIOD    (F_CPU) / 256

static int  led_mode;


void __ISR(_TIMER_2_VECTOR, IPL2AUTO) led_blink(void)
{
    switch (led_mode) {
        case 0:
    }
    LATFbits.LATF1 ^= 1;
    IFS0bits.T2IF = 0;
}

void __ISR(_EXTERNAL_1_VECTOR, IPL3AUTO) button_press(void)
{
    PR2 /= 2;
    if (PR2 < F_PERIOD / 16)
        PR2 = F_PERIOD;
    IFS0bits.INT1IF = 0;
    TMR2 = 0;
}

void setup_timer(void)
{
    T2CONbits.TCKPS = 0b111;
    PR2 = F_PERIOD;
    T2CONbits.ON = 1;
}

void setup_interrupts(void)
{
    // Multi-vector mode ON
    INTCONbits.MVEC = 1;
    // Timer2
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 2;
    IPC2bits.T2IS = 0;
    IEC0bits.T2IE = 1;
    // Button
    IFS0bits.INT1IF = 0;
    IPC1bits.INT1IP = 3;
    IPC1bits.INT1IS = 0;
    IEC0bits.INT1IE = 1;
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
    INTEnableInterrupts();
    while (1) {
        clear_watchdog();
    }
}
