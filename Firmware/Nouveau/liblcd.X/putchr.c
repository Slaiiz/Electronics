#include "liblcd.h"

void    liblcd_putchr(UINT8 c)
{
    liblcd_send(c, 1);
    ++_curcol;
}