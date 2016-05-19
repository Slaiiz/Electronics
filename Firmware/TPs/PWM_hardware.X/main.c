/* 
 * File:   main.c
 * Author: schiad
 *
 * Created on March 30, 2016, 12:17 PM
 */

/*
 * 
 */

#include <xc.h>
#include <sys/attribs.h> // This unlocks the __ISR macro

#include "types.h"

void    configure_timer_type_b(u8 ratio, u32 pr5)
{
    T5CON = 0;
    // Enable timer
    T5CONbits.ON = 1;
    // ratio 1:256
    T5CONbits.TCKPS = ratio;
    PR5 = pr5;
    TMR5 = 0;
}

void config_comparateur(u32 periode, u32 on)
{
    INTEnableSystemMultiVectoredInt();// Enable system wide interrupt to // multivectored mode.

    OC1CON          = 0x0000;
    OC1R            = on;
    OC1RS           = periode;
    OC1CONbits.OCM  = 0b110;    // configure for PWM mode without Fault Pin

    configure_timer_type_b(0b0, periode);

    IFS0CLR = 0x00000100;       // clear t2 interrupt flag
    IEC0SET = 0x00000100;       // enable t2 interrupt
    IPC2SET = 0x0000001C;       // set t2 priority to 7

    OC1CONSET   = 0x8000;       // Enable OC1

}


void main(void) {



}

