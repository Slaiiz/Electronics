/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on March 24, 2016, 4:31 PM
 */

#include "p32xxxx.h"
#include "types.h"

void    configure_timer_type_a(u8 ratio)
{
    // Enable timer
    T1CONbits.ON = 1;
    // Timer is external
    T1CONbits.TCS = 1;
    // 1:1 clock ratio
    T1CONbits.TCKPS = ratio;
}

void    configure_timer_type_b(u8 ratio)
{
    // Enable timer
    T2CONbits.ON = 1;
    // ratio 1:256
    T2CONbits.TCKPS = ratio;
    // 32bits mode
    T2CONbits.T32 = 1;
}


// using timer type B
/*
void    main(void)
{
    u16 half_hz;
    u8  bouton;
    u8  last_bouton;
    u16 periode;

    periode = 536;
    configure_timer_type_b(0b000);
    half_hz = 8;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR2 % periode < periode / 2)
            PORTFbits.RF1 = 1;
        else
            PORTFbits.RF1 = 0;
        if (!last_bouton && bouton)
        {
            if (half_hz <= 8)
                half_hz *= 2;
            else
                half_hz =  1;
        }
        bouton      = last_bouton;
        last_bouton = PORTDbits.RD8;
    }
}
*/
// using RTC timer (type A).


void    main(void)
{
    u16 half_hz;
    u8  bouton;
    u8  last_bouton;

    configure_timer_type_a(0);
    half_hz = 1;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR1 % (65536 / half_hz) < (65536 / (half_hz * 2)))
            PORTFbits.RF1 = 1;
        else
            PORTFbits.RF1 = 0;
        if (!last_bouton && bouton)
        {
            if (half_hz <= 8)
                half_hz *= 2;
            else
                half_hz =  1;
        }
        bouton      = last_bouton;
        last_bouton = PORTDbits.RD8;
    }
}