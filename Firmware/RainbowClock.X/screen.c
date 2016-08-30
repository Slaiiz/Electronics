#include "rainbowclock.h"

//void __attribute__((vector(_TIMER_1_VECTOR),interrupt(IPL1AUTO)))
//screen_refresh(void)
//{
//    char            buf[32];
//    static uint32_t temp;
//    uint32_t        delt;
//    static uint32_t max;
//    uint32_t        i;
//    uint8_t         l;
//
//    refresh_clock();
//    libpixel_clear(pixels);
//    max = average > max ? average : max;
//    delt = (average * average) / 4271;
//    for (i = 0; i < 60; ++i)
//        libpixel_set(pixels, i, delt, delt, delt);
//    libpixel_show(pixels);
//    IFS0bits.T1IF  = 0;
//}
