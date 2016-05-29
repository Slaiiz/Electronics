/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include "rainbowclock.h"

typedef UINT32 BMP280_S32_t;
UINT8   tmp;
UINT32  adc_T;
UINT16  dig_T1;
UINT32  mode  = 5;
UINT32  temp  = 0;
INT16   dig_T2, dig_T3;
UINT8   buffer[32];
UINT32  temperature;
UINT32  t_fine;

void    update_clock(UINT32 y, UINT32 M, UINT32 d, UINT32 wd, UINT32 h, UINT32 m, UINT32 s)
{
    char *days[7] = {"DIM", "LUN", "MAR", "MER", "JEU", "VEN", "SAM"};

    liblcd_clear();
    liblcd_mvputchr('0' + h / 10, 4, 0);
    liblcd_putchr('0' + h % 10);
    liblcd_putchr(':');
    liblcd_putchr('0' + m / 10);
    liblcd_putchr('0' + m % 10);
    liblcd_putchr(':');
    liblcd_putchr('0' + s / 10);
    liblcd_putchr('0' + s % 10);
    liblcd_mvputstr(days[wd], 1, 1);
    liblcd_putchr(' ');
    liblcd_putchr('0' + d / 10);
    liblcd_putchr('0' + d % 10);
    liblcd_putchr('/');
    liblcd_putchr('0' + M / 10);
    liblcd_putchr('0' + M % 10);
    liblcd_putchr('/');
    liblcd_putchr('2');
    liblcd_putchr('0');
    liblcd_putchr('0' + y / 10);
    liblcd_putchr('0' + y % 10);
}

UINT32 bmp280_temperature(UINT32 a)
{
    UINT32  b, c;

    b = ((a >> 14) - (dig_T1 >> 10)) * dig_T2;
    c = (((a >> 17) - (dig_T1 >> 13)) * ((a >> 17) - (dig_T1 >> 13))) * dig_T3;
    t_fine = (b + c);
    return ((b + c) >> 12);
}

UINT32 bcd_to_dec(UINT32 n)
{
    return (n / 16 * 10 + n % 16);
}

UINT32 dec_to_bcd(UINT32 n)
{
    return  (n / 10 * 16 + n % 10);
}

void __attribute__((vector(_TIMER_1_VECTOR),interrupt(IPL1AUTO)))
timer_tick(void)
{
    UINT32  seconds;
    UINT32  minutes;
    UINT32  hours;
    UINT32  wday;
    UINT32  day;
    UINT32  month;
    UINT32  year;
    UINT8   pixel;
    UINT32  i;
    libneopixels_clear();
    switch (mode) {
        case 0:
            libneopixels_set(pixel + 0, 0, 0, 0);
            libneopixels_set((pixel + 1) % 60, 28, 0, 0);
            libneopixels_set((pixel + 2) % 60, 0, 90, 0);
            libneopixels_set((pixel + 3) % 60, 0, 0, 28);
            libneopixels_set((pixel + 4) % 60, 0, 0, 0);
            pixel = (pixel + 1) % 60;
            libneopixels_show();
            break ;
        case 1:
            seconds = bcd_to_dec((RTCTIME & 0x0000FF00) >> 8);
            minutes = bcd_to_dec((RTCTIME & 0x00FF0000) >> 16);
            hours   = bcd_to_dec((RTCTIME & 0xFF000000) >> 24);
            wday    = bcd_to_dec((RTCDATE & 0x000000FF));
            day     = bcd_to_dec((RTCDATE & 0x0000FF00) >> 8);
            month   = bcd_to_dec((RTCDATE & 0x00FF0000) >> 16);
            year    = bcd_to_dec((RTCDATE & 0xFF000000) >> 24);
            libneopixels_clear();
            // Sectors
            for (i = 0; i < 60; i++) {
                if (!(i % 5))
                    libneopixels_set(i, 20, 20, 0);
                else {
                    libneopixels_set(i, 1, 1, 1);
                }
            }
            // Hours
            i = 60 - (60 * (hours % 12) / 12);
            libneopixels_set((i - minutes / 12) % 60, 255, 0, 0);
            libneopixels_set((i - 1 - minutes / 12) % 60, 30, 0, 0);
            libneopixels_set((i + 1 - minutes / 12) % 60, 30, 0, 0);
            // Minutes
            i = 60 - minutes;
            libneopixels_set(i % 60, 0, 255 * seconds / 59, 0);
            libneopixels_set((i + 1) % 60, 0, 255 - 255 * seconds / 59, 0);
            // Seconds
            libneopixels_set((60 - seconds) % 60, 0, 0, 255);
            libneopixels_show();
            update_clock(year, month, day, wday, hours, minutes, seconds);
            break ;
        case 2:
            for (pixel = 0; pixel < 60; pixel++) {
                libneopixels_set(pixel, 0, 255 * (pixel + i) / 60, 0);
            }
            libneopixels_show();
            i = (i + 1) % 60;
            break ;
        case 3:
            for (pixel = 0; pixel < 60; pixel++) {
                libneopixels_set(pixel, seconds, seconds, seconds);
            }
            seconds = (seconds + 1) % 255;
            libneopixels_show();
            break ;
        case 4:
            i = 1;
            for (pixel = 0; pixel < 16; pixel++) {
                libneopixels_set(pixel, ((seconds & i) && 1) * 255, 0, 0);
                i <<= 1;
            }
            seconds = (seconds + 1);
            libneopixels_show();
            break ;
        case 5:
            libi2c_read(I2C1, BME280_ADDRESS, 0xFA, (UINT8*)&adc_T, 3);
            adc_T = (adc_T - 7000) / 748;
            OC3R = 1000 / adc_T;
            PR2  = 1000 / adc_T;
            for (pixel = 0; pixel < adc_T; ++pixel)
                libneopixels_set(pixel, pixel, 60 - pixel, 0);
            libneopixels_show();
            break ;
    }
    IFS0bits.T1IF = 0;
}

void __attribute__((vector(_EXTERNAL_0_VECTOR),interrupt(IPL2AUTO)))
     button_press(void)
{
    libneopixels_clear();
    mode = (mode + 1) % 6;
    IFS0bits.INT0IF = 0;
}

void setup_callbacks(void)
{
    TMR1 = 0;
    PR1 = 32768 / 100;
    T1CONbits.TCKPS = 0;
    T1CONbits.TCS   = 1;
    T1CONbits.ON    = 1;
    INTCONbits.MVEC = 1;
    // Timer1
    IFS0bits.T1IF   = 0;
    IPC1bits.T1IP   = 1;
    IPC1bits.T1IS   = 0;
    IEC0bits.T1IE   = 1;
    // Button
    IFS0bits.INT0IF = 0;
    IPC0bits.INT0IP = 2;
    IPC0bits.INT0IS = 0;
    IEC0bits.INT0IE = 1;
    asm volatile ("ei");
}

void enable_RTCC()
{
    UINT32 time = 0;
    RtccWrEnable(1);
    RTCCONbits.ON = 0;
    while (RTCCONbits.RTCCLKON);
    RTCCONbits.ON = 1;
    while (!RTCCONbits.RTCCLKON);
    RTCCONbits.RTCOE = 1;
    RtccWrEnable(0);
}

void configure_real_time_clock(UINT8 year, UINT8 month, UINT8 day, UINT8 wday, UINT8 hours, UINT8 minutes, UINT8 seconds)
{
    UINT32 time = 0;
    UINT32 date = 0;
    RtccWrEnable(1);
    RTCCONbits.ON = 0;
    date = dec_to_bcd(year) << 24;
        + dec_to_bcd(month) << 16;
        + dec_to_bcd(day)   << 8;
        + dec_to_bcd(wday)  << 0;
    time = dec_to_bcd(hours)  << 24;
        + dec_to_bcd(minutes) << 16;
        + dec_to_bcd(seconds) << 8;
    while (RTCCONbits.RTCCLKON);
    RTCTIME = time;
    RTCDATE = date;
    RTCCONbits.ON = 1;
    while (!RTCCONbits.RTCCLKON);
    RTCCONbits.RTCOE = 1;
    RtccWrEnable(0);
}

void configure_ports(void)
{
    TRISFbits.TRISF1   = 0;
    TRISBbits.TRISB1   = 0;
    TRISFbits.TRISF6   = 1;
}

void main(void)
{
    UINT8   req[4] = {0xF4, 0x27, 0xF5, 0x00};

    SYSTEMConfigPerformance(F_CPU);
    liblcd_light(1);
    liblcd_begin(16, 2);
    liblcd_move(4, 0);
    configure_ports();
    enable_RTCC();
    libneopixels_begin(&LATB, 1, 60);
    setup_callbacks();
    libserial_begin(9600);
    libi2c_enable(I2C1, STANDARD);
    libi2c_write(I2C1, BME280_ADDRESS, req, sizeof(req));
    libi2c_read(I2C1, BME280_ADDRESS, 0x88, (UINT8*)&dig_T1, 2);
    libi2c_read(I2C1, BME280_ADDRESS, 0x8A, (UINT8*)&dig_T2, 2);
    libi2c_read(I2C1, BME280_ADDRESS, 0x8C, (UINT8*)&dig_T3, 2);
    T2CONbits.TCKPS = 0b111;
    T2CONbits.ON    = 1;
    OC3CONbits.OCM  = 0b11;
    OC3CONbits.ON   = 1;
    while (1);
}
