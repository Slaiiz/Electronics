#include "liblcd.h"

void    liblcd_command(UINT8 cmd)
{
    liblcd_send(cmd, 0);
}