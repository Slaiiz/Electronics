/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 4, 2016, 6:42 PM
 */

#include <xc.h>
#include <sys/attribs.h>


// PIC32MX340F512H Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// DEVCFG3
// USERID = No Setting

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (12x Divider)
#pragma config FPLLMUL = MUL_16         // PLL Multiplier (24x Multiplier)
#pragma config FPLLODIV = DIV_8         // System PLL Output Clock Divider (PLL Divide by 256)

// DEVCFG1
#pragma config FNOSC = FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)

void __ISR(_OUTPUT_COMPARE_1_VECTOR, IPL1AUTO) led_blink(void)
{
    LATFbits.LATF1   ^= 1;
    OC1RS            += 1;
    IFS0bits.OC1IF    = 0;
}

void main(void)
{
    INTCONbits.MVEC   = 1;
    TRISFbits.TRISF1  = 0;
    PR2               = 1024;
    T2CONbits.TCKPS   = 0b111;
    T2CONbits.ON      = 1;
    OC1CON            = 0;
    OC1R              = 1024;
    OC1RS             = 1024;
    OC1CONbits.OCTSEL = 0;
    OC1CONbits.OCM    = 0b110;
    OC1CONbits.ON     = 1;
    IFS0bits.OC1IF    = 0;
    IPC1bits.OC1IP    = 1;
    IPC1bits.OC1IS    = 0;
    IEC0bits.OC1IE    = 1;
    asm volatile("ei");
    while (1);
}
