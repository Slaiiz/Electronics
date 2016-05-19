/*
 * File:   main.c
 * Author: bocal
 *
 * Created on March 24, 2016, 4:31 PM
 */

#include "p32xxxx.h"
#include "types.h"

void    configure_timer_type_a(u8 ratio, u32 pr1)
{
    T1CON = 0;
    // Enable timer
    T1CONbits.ON = 1;
    // ratio 1:256
    T1CONbits.TCKPS = ratio;
    // 32bits mode
    //T1CONbits.T32 = 1;
    PR1 = pr1;
    TMR1 = 0;
}

void    configure_timer_type_b(u8 ratio, u32 pr2)
{
    T2CON = 0;
    // Enable timer
    T2CONbits.ON = 1;
    // ratio 1:256
    T2CONbits.TCKPS = ratio;
    // 32bits mode
    T2CONbits.T32 = 1;
    PR2 = pr2;
    TMR2 = 0;
}

// using timer type B
void    main(void)
{
    u8  bouton;
    u8  last_bouton;
    u16 pr2;
    u16 min;
    pr2 = 46875;
    min = 5859;

    configure_timer_type_b(0b111, pr2);
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR2 < (pr2 / 2))
            LATFbits.LATF1 = 1;
        else
            LATFbits.LATF1 = 0;
        if (!last_bouton && bouton)
        {
            pr2 = pr2 / 2;
            if (pr2 < min)
                pr2 = 1980;
            configure_timer_type_b(0b111, pr2);
        }
        bouton      = last_bouton;
        last_bouton = PORTDbits.RD8;
    }
}



// using RTC timer (type A).

/*
void    main(void)
{
    u16 half_hz;
    u8  bouton;
    u8  last_bouton;
    u32 sec;

    sec = 65536;
    configure_timer_type_a(0b00, sec);
    half_hz = 1;
    TRISFbits.TRISF1 = 0;
    TRISDbits.TRISD8 = 1;
    while (1) {
        if (TMR1 % (sec / half_hz) < (sec / (half_hz * 2)))
            LATFbits.LATF1 = 1;
        else
            LATFbits.LATF1 = 0;
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
}*/