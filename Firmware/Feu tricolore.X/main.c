/* 
 * File:   main.c
 * Author: bocal
 *
 * Created on March 25, 2016, 4:32 PM
 */

#include <xc.h>

void    configure_timer(void)
{
    // Our timer is enabled
    T1CONbits.ON = 1;
    // It's also external
    T1CONbits.TCS = 1;
    // And it has a ratio of 1:8
    T1CONbits.TCKPS = 1;
}

void    main(void)
{
    unsigned short  time;

    _TRISB0 = 0;
    _TRISB1 = 0;
    _TRISB2 = 0;
    configure_timer();
    while (1) {
        time = TMR1;
        _RB0 = 1;
        while (TMR1 - time < 30000);
        time = TMR1;
        _RB0 = 0;
        _RB1 = 1;
        while (TMR1 - time < 7000);
        _RB1 = 0;
        _RB2 = 1;
        // Wait until the timer wraps back to zero (with a little delay)
        while (TMR1 > 100);
        _RB2 = 0;
    }
    return ; // Aint' gonna happen
}
