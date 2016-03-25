/*
 * File:   main.c
 * Author: bocal
 *
 * Created on March 24, 2016, 4:31 PM
 */

#include "p32xxxx.h"

void    main(void)
{
    _RF1 = 0; // wtf
    _TRISF1 = 0;
    _TRISD8 = 1;
    while (1) {
        while (!_RD8);
        while (_RD8);
        _RF1 ^= 1;
    }
}
