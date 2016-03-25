#include <xc.h>

void    configure_timer(void)
{
    T1CONbits.ON = 1;
    T1CONbits.TCS = 1;
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
        time = TMR1;
        _RB1 = 0;
        _RB2 = 1;
        while (TMR1 > 1000);
        _RB2 = 0;
    }
    return ;
}
