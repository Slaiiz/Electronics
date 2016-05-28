#include "libserial.h"

UINT8   libserial_getchr(void)
{
    UINT8   c;

    if (libserial_available()) {
        c = U1RXREG;
        if (U1STA & 2)
            U1STACLR = 2;
        return (c);
    }
    return ('\0');
}
