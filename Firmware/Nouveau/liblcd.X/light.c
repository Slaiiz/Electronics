#include "liblcd.h"

void    liblcd_light(UINT8 mode)
{
    LATFbits.LATF5 = mode;
}