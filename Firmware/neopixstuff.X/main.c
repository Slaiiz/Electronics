/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include "rainbowclock.h"
#include "lcd.h"

UINT8   _background[] = {1, 1, 1};
UINT8   _mark[] = {20, 20, 0};
UINT8   _hours[] = {255, 0, 0};
UINT8   _minutes[] = {0, 255, 0};
UINT8   _secondes[] = {0, 0, 255};

UINT8   R, G, B;

typedef UINT32 BMP280_S32_t;
UINT8   tmp;
UINT32  adc_T;
UINT16  dig_T1;
UINT32  mode  = 5;
UINT32  temp  = 0;
INT16   dig_T2, dig_T3;
//UINT8   buffer[32];
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
    UINT32          seconds;
    UINT32          minutes;
    UINT32          hours;
    UINT32          wday;
    UINT32          day;
    UINT32          month;
    UINT32          year;
    UINT8 static    pixel;
    UINT32          i;
    seconds = bcd_to_dec((RTCTIME & 0x0000FF00) >> 8);
    minutes = bcd_to_dec((RTCTIME & 0x00FF0000) >> 16);
    hours   = bcd_to_dec((RTCTIME & 0xFF000000) >> 24);
    wday    = bcd_to_dec((RTCDATE & 0x000000FF));
    day     = bcd_to_dec((RTCDATE & 0x0000FF00) >> 8);
    month   = bcd_to_dec((RTCDATE & 0x00FF0000) >> 16);
    year    = bcd_to_dec((RTCDATE & 0xFF000000) >> 24);
    if (year > 99)
        conf_RTCC_str("S3801192031408");
    update_clock(year, month, day, wday, hours, minutes, seconds);
    libserial_display_clock(year, month, day, wday, hours, minutes, seconds);
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
            // Sectors
            for (i = 0; i < 60; i++) {
                if (!(i % 5))
                    libneopixels_set(i, _mark[0], _mark[1], _mark[2]);
                else {
                    libneopixels_set(i, _background[0], _background[1], _background[2]);
                }
            }
            // Hours
            i = 60 - (60 * (hours % 12) / 12);
            libneopixels_set((i - minutes / 12) % 60, _hours[0], _hours[1], _hours[2]);
            libneopixels_set((i - 1 - minutes / 12) % 60, _hours[0] / 3, _hours[1] / 3, _hours[2] / 3);
            libneopixels_set((i + 1 - minutes / 12) % 60, _hours[0] / 3, _hours[1] / 3, _hours[2] / 3);
            // Minutes
            i = 60 - minutes;
            libneopixels_set(i % 60, _minutes[0] * seconds / 60, _minutes[1] * seconds / 60, _minutes[2] * seconds / 60);
            libneopixels_set((i + 1) % 60, _minutes[0] * (60 - seconds) / 60, _minutes[1] * (60 - seconds) / 60, _minutes[2] * (60 - seconds) / 60);
            // Seconds
            libneopixels_set((60 - seconds) % 60, _secondes[0], _secondes[1], _secondes[2]);
            libneopixels_show();
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
//            libi2c_read(0, BME280_ADDRESS, 0x88, &tmp);
//            dig_T1 = tmp;
//            libi2c_read(0, BME280_ADDRESS, 0x89, &tmp);
//            dig_T1 |= tmp << 8;
//            libi2c_read(0, BME280_ADDRESS, 0x8A, &tmp);
//            dig_T2 = tmp;
//            libi2c_read(0, BME280_ADDRESS, 0x8B, &tmp);
//            dig_T2 |= tmp << 8;
//            libi2c_read(0, BME280_ADDRESS, 0x8C, &tmp);
//            dig_T3 = tmp;
//            libi2c_read(0, BME280_ADDRESS, 0x8D, &tmp);
//            dig_T3 |= tmp << 8;
//            libi2c_read(0, BME280_ADDRESS, 0xF9, &tmp);
//            adc_T = tmp;
//            libi2c_read(0, BME280_ADDRESS, 0xF8, &tmp);
//            adc_T |= tmp << 4;
//            libi2c_read(0, BME280_ADDRESS, 0xF7, &tmp);
//            adc_T |= tmp << 8;
//
//            var1 = (((adc_T >> 3) - (dig_T1 << 1)) * dig_T2) >> 11;
//            var2 = (((((adc_T >> 4) - dig_T1) * ((adc_T >> 4) - dig_T1)) >> 12) * dig_T3) >> 14;
//            temp = ((var1 + var2) * 5 + 128) >> 8;
            libi2c_read(0, 104, 0x00, &tmp);
            for (pixel = 0; pixel < tmp; ++pixel) {
                i = 32 * pixel / 60;
                libneopixels_set(pixel, i, 32 - i, 0);
            }
            libneopixels_show();
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
    PR1 = 32768 / 2;
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

void configure_real_time_clock(UINT8 year, UINT8 month, UINT8 day,
        UINT8 wday, UINT8 hours, UINT8 minutes, UINT8 seconds)
{
    UINT32 time = 0;
    UINT32 date = 0;
    RtccWrEnable(1);
    RTCCONbits.ON = 0;
    date += dec_to_bcd(year) << 24;
    date += dec_to_bcd(month) << 16;
    date += dec_to_bcd(day) << 8;
    date += dec_to_bcd(wday);
    time += dec_to_bcd(hours) << 24;
    time += dec_to_bcd(minutes) << 16;
    time += dec_to_bcd(seconds) << 8;
    while (RTCCONbits.RTCCLKON);
    RTCTIME = time;
    RTCDATE = date;
    RTCCONbits.ON = 1;
    while (!RTCCONbits.RTCCLKON);
    RTCCONbits.RTCOE = 1;
    RtccWrEnable(0);
}

void conf_RTCC_str(UINT8 *str)
{
    UINT8 y, M, d, w, h, m, s;
    y = M = d = w = h = m = s = 0;
    y = (10 * (str[1] - '0')) + str[2] - '0';
    M = (10 * (str[3] - '0')) + str[4] - '0';
    d = (10 * (str[5] - '0')) + str[6] - '0';
    w = str[7] - '0';
    h = (10 * (str[8] - '0')) + str[9] - '0';
    m = (10 * (str[10] - '0')) + str[11] - '0';
    s = (10 * (str[12] - '0')) + str[13] - '0';
    configure_real_time_clock(y, M, d, w, h, m, s);
}

void configure_ports(void)
{
    TRISFbits.TRISF1   = 0;
    TRISBbits.TRISB1   = 0;
    TRISFbits.TRISF6   = 1;
}

void main(void)
{
    UINT8   req[2];
    UINT8   str[100];

    SYSTEMConfigPerformance(8000000);
    libserial_begin(9600);
    liblcd_light(1);
    liblcd_begin(16, 2);
    liblcd_move(4, 0);
    configure_ports();
    enable_RTCC();
    libneopixels_begin(&LATB, 1, 60);
    setup_callbacks();
    libi2c_enable(0, STANDARD);
    req[0] = 0x07;
    req[1] = 0x93;
    libi2c_write(0, 104, req, 2);
    req[0] = 0x00;
    req[1] = 0x01;
    libi2c_write(0, 104, req, 2);
    while (1)
    {
        if (libserial_getstr(str))
        {
            liblcd_mvputstr(str, 0, 0);
            if (str[0] == 'S')
                conf_RTCC_str(str);
            else if (str[0] == 'M')
                mode = str[1] - '0';
            else if (str[0] == 'R')
                R = atoi(&str[1]);
            else if (str[0] == 'G')
                G = atoi(&str[1]);
            else if (str[0] == 'B')
                B = atoi(&str[1]);
            else if (str[0] == 'b')
            {
                _background[0] = R;
                _background[1] = G;
                _background[2] = B;
            }
            else if (str[0] == 'n')
            {
                _mark[0] = R;
                _mark[1] = G;
                _mark[2] = B;
            }
            else if (str[0] == 'h')
            {
                _hours[0] = R;
                _hours[1] = G;
                _hours[2] = B;
            }
            else if (str[0] == 'm')
            {
                _minutes[0] = R;
                _minutes[1] = G;
                _minutes[2] = B;
            }
            else if (str[0] == 's')
            {
                _secondes[0] = R;
                _secondes[1] = G;
                _secondes[2] = B;
            }
        }
    }
}
