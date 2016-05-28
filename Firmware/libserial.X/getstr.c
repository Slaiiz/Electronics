#include "libserial.h"

UINT32   libserial_getstr(UINT8 *str)
{
    UINT32  i = 0;
    UINT32  j = 0;
    UINT8   line = 0;
    while (i < 100 && j < 20000 && !line)
    {
        delay_micros(1);
        if (libserial_available())
        {
            str[i] = libserial_getchr();
            if (str[i] == '\r' || str[i] == '\n')
                line = 1;
            else
                i++;
            j = 0;
        }
        else
        {
            str[i] = '\0';
            j++;
        }
    }
    i++;
    str[i] = '\0';
    return (i);
}