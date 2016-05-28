#include "libserial.h"

void    libserial_putstr(UINT8 *str)
{
    UINT32  i = 0;
    while (str[i]) {
        libserial_putchr(str[i]);
        i++;
    }
}
