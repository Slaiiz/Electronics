#include "libserial.h"

void    libserial_begin(UINT16 speed)
{
    U1MODEbits.ON    = 0;   // disable uart
    IFS0bits.U1RXIF  = 0;   // clear rx interrupt flag
    IEC0bits.U1RXIE  = 1;   // enable Rx interrupts
    U1MODEbits.STSEL = 0;   // 1 stop bit
    U1MODEbits.PDSEL = 0;   // 8 bits data no parity
    U1MODEbits.BRGH  = 0;   // 16x baud clock enable
    U1MODEbits.RXINV = 0;   // Idle state is 1
    U1STAbits.URXEN  = 1;   // Enable control of ur pin
    U1STAbits.UTXEN  = 1;   // Enable control of ut pin

    U1BRG = ((8000000 / (16 * speed)) - 1);
    U1MODEbits.ON = 1;      // Enable uart
}
