#include "libserial.h"

void    libserial_putchr(UINT8 ch)
{
    while (U1STAbits.UTXBF);
    U1TXREG = ch;
}
