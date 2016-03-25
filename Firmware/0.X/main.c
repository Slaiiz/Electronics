/* 
 * File:   main.c
 * Author: schiad
 *
 * Created on 23 mars 2016, 13:38
 */

#include <p32xxxx.h>

int main(void)
{
    TRISFbits.TRISF1 = 0;
    while(1)
    {
        LATFbits.LATF1 = 0;
        LATFbits.LATF1 = 1;
    }
    return (0);
}

