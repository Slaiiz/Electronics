#include "rainbowclock.h"

SCHEME color = {
    {10, 10, 10}, {30, 30, 70}, /* BG, MK */
    {255, 0, 0}, {0, 255, 0},   /* HR, MN */
    {0, 0, 255}                 /* SC     */
};

static void     sample_brightness(uint32_t *in)
{
    AD1CON1bits.SAMP = 1;
    libsys_delay_micros(10);
    AD1CON1bits.SAMP = 0;
    while (!AD1CON1bits.DONE);
    *in = (*in + ADC1BUF0) / 2;
}

static void     draw_markers(void)
{
    uint32_t i;

    libpixel_clear(pixels);
    for (i = 0; i < 60; ++i) {
        if (!(i % 5))
            libpixel_set(pixels, i, color.mk.r, color.mk.g, color.mk.b);
        else
            libpixel_set(pixels, i, color.bg.r, color.bg.g, color.bg.b);
    }
}

static uint8_t  long_month(uint8_t m, uint8_t y)
{
    if (m == 2) {
        if (!(y % 4) && (y % 100))
            return (29);
        return (28);
    }
    else if ((m >= 8) != (m % 2))
        return (31);
    return (30);
}

void ISR(_TIMER_1_VECTOR,IPL1AUTO) clock_refresh(void)
{
    uint32_t static average;
    uint16_t        tmp;

    draw_markers();
    /*  hours ---------------------------------- */
    tmp = (5 * (date.hours % 12)) + date.minutes / 11;
    libpixel_set(pixels, (tmp + 59) % 60,
        color.hr.r,
        color.hr.g,
        color.hr.b);
    libpixel_set(pixels, tmp % 60,
        color.hr.r,
        color.hr.g,
        color.hr.b);
    libpixel_set(pixels, (tmp +  1) % 60,
        color.hr.r,
        color.hr.g,
        color.hr.b);
    /* minutes --------------------------------- */
    libpixel_set(pixels, date.minutes,
       color.mn.r - color.mn.r * (date.seconds) / 59,
       color.mn.g - color.mn.g * (date.seconds) / 59,
       color.mn.b - color.mn.b * (date.seconds) / 59);
    libpixel_set(pixels, (date.minutes + 1) % 60,
        color.mn.r * (date.seconds) / 59,
        color.mn.g * (date.seconds) / 59,
        color.mn.b * (date.seconds / 59));
    /* seconds --------------------------------- */
    libpixel_set(pixels, date.seconds,
        color.sc.r,
        color.sc.g,
        color.sc.b);
    sample_brightness(&average);
    libpixel_brightness(pixels, 255 * (average - 130) / 1023);
    libpixel_show(pixels);
    if (!(date.millis))
        menu_update(menu, lcd);
    date.millis = (date.millis + 100) % 1000    ;
    if (!date.millis) {
        date.seconds = (date.seconds + 1) % 60;
        if (!date.seconds) {
            date.minutes = (date.minutes + 1) % 60;
            if (!date.minutes) {
                date.hours = (date.hours + 1) % 24;
                if (!date.hours) {
                    date.day = date.day % 31 + 1;
                    if (!date.day) {
                        date.month = date.month % 12 + 1;
                        if (!date.month) {
                            date.year = (date.year + 1);
                        }
                    }
                    if (date.day > long_month(date.month, date.year))
                        date.day = 1;
                    date.day_of_week = tondering_day_of_week();
                }
            }
        }
    }
    IFS0bits.T1IF = 0;
}
