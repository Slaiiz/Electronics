/*
 * File:   main.c
 * Author: bocal
 *
 * Created on March 24, 2016, 4:31 PM
 */

#include "p32xxxx.h"
#include "types.h"

void    main(void)
{
    u8  button;
    u8  last_button;

    _RF1 = 0; // wtf
    _TRISF1 = 0;
    _TRISD8 = 1;
    while(42)
    {
        button      = last_button;
        last_button = PORTDbits.RD8;
        if (!last_button && button)
        {
            _RF1 ^= 1;
        }
    }
}