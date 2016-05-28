#include "libserial.h"

void    main()
{
    SYSTEMConfigPerformance(8000000);
    UINT8  serial[100];
    libserial_begin(9600);
    while (1)
    {
        if (libserial_available())
        {
            libserial_getstr(serial);
            libserial_putstr(">>>");
            libserial_putstr(serial);
            libserial_putchr('\n');
        }
    }
}