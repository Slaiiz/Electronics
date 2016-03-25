/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on March 24, 2016, 4:31 PM
 */

#include "p32xxxx.h"
#include "types.h"

void    configure_timer(void)
{
    // Enable timer
    T1CONbits.ON = 1;
    // Timer is external
    T1CONbits.TCS = 1;
    // 1:1 clock ratio
    T1CONbits.TCKPS = 0;
}

void    main(void)
{
    u16 hz;
    u8  bouton;

    configure_timer();
    hz = 1;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR1 % (32768 / hz) < (32768 / (hz * 2)))
            PORTFbits.RF1 = 1;
        else
            PORTFbits.RF1 = 0;
        if (!PORTDbits.RD8 && bouton)
        {
            if (hz < 4)
                hz *= 2;
            else
                hz =  1;
        }
        bouton = PORTDbits.RD8;
    }

}
