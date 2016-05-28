#include "liblcd.h"

void    liblcd_putstr(UINT8 *s)
{
    while (*s != '\0') {
        if (_curcol >= _numcol || *s == '\n') {
            liblcd_move(0, ++_currow);
            if (*s == '\n' && ++s)
                continue ;
        }
        liblcd_putchr(*s++);
    }
}
