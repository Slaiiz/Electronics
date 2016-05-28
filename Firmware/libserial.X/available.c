#include "libserial.h"

UINT8   libserial_available(void)
{
    return (U1STAbits.URXDA);
}
