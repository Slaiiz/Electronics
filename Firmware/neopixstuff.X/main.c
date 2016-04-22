/* 
 * File:   main.c
 * Author: vchesnea
 *
 * Created on April 7, 2016, 4:29 PM
 */

#include "rainbowclock.h"

static long mode = 0;

void __attribute__((vector(_TIMER_1_VECTOR),interrupt(IPL1AUTO)))
     timer_tick(void)
{
    unsigned int            seconds;
    unsigned int            minutes;
    unsigned int            hours;
    static char             pixel;
    int                     i;

    switch (mode) {
        case 0:
            neopixels_set(pixel + 0, 0, 0, 0);
            neopixels_set((pixel + 1) % 60, 28, 0, 0);
            neopixels_set((pixel + 2) % 60, 0, 90, 0);
            neopixels_set((pixel + 3) % 60, 0, 0, 28);
            neopixels_set((pixel + 4) % 60, 0, 0, 0);
            pixel = (pixel + 1) % 60;
            neopixels_show();
            break ;
        case 1:
            seconds = bcd_to_dec((RTCTIME & 0x0000FF00) >> 8);
            minutes = bcd_to_dec((RTCTIME & 0x00FF0000) >> 16);
            hours   = bcd_to_dec((RTCTIME & 0xFF000000) >> 24);
            neopixels_clear();
            // Sectors
            for (i = 0; i < 60; i++) {
                if (!(i % 5))
                    neopixels_set(i, 20, 20, 0);
                else {
                    neopixels_set(i, 1, 1, 1);
                }
            }
            // Hours
            i = 60 - (60 * (hours % 12) / 12);
            neopixels_set((i - minutes / 12) % 60, 255, 0, 0);
            neopixels_set((i - 1 - minutes / 12) % 60, 30, 0, 0);
            neopixels_set((i + 1 - minutes / 12) % 60, 30, 0, 0);
            // Minutes
            i = 60 - minutes;
            neopixels_set(i % 60, 0, 255 * seconds / 59, 0);
            neopixels_set((i + 1) % 60, 0, 255 - 255 * seconds / 59, 0);
            // Seconds
            neopixels_set((60 - seconds) % 60, 0, 0, 255);
            neopixels_show();
            break ;
        case 2:
            for (pixel = 0; pixel < 60; pixel++) {
                neopixels_set(pixel, 0, 255 * (pixel + i) / 60, 0);
            }
            neopixels_show();
            i = (i + 1) % 60;
            break ;
        case 3:
            for (pixel = 0; pixel < 60; pixel++) {
                neopixels_set(pixel, seconds, seconds, seconds);
            }
            seconds = (seconds + 1) % 255;
            neopixels_show();
            break ;
        case 4:
            i = 1;
            for (pixel = 0; pixel < 16; pixel++) {
                neopixels_set(pixel, ((seconds & i) && 1) * 255, 0, 0);
                i <<= 1;
            }
            seconds = (seconds + 1);
            neopixels_show();
            break ;
        case 5:
            for (pixel = 0; pixel < 60; pixel++) {
                i = 255 * pixel / 60;
                neopixels_set(pixel, i, 255 - i, 0);
            }
            neopixels_show();
    }
    IFS0bits.T1IF = 0;
}

void __attribute__((vector(_EXTERNAL_0_VECTOR),interrupt(IPL2AUTO)))
     button_press(void)
{
    neopixels_clear();
    mode = (mode + 1) % 6;
    IFS0bits.INT0IF = 0;
}

void setup_callbacks(void)
{
    TMR1 = 0;
    PR1 = 32768 / 10;
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
    asm volatile("ei");
}

void configure_realtime_clock(void)
{
    RtccWrEnable(1);
    RTCCONbits.ON = 0;
    while (RTCCONbits.RTCCLKON);
    RTCTIME = 0x18515800;
    RTCCONbits.ON = 1;
    while (!RTCCONbits.RTCCLKON);
    RTCCONbits.RTCOE = 1;
    RtccWrEnable(0);
}

void configure_ports(void)
{
    TRISBbits.TRISB0   = 0;
    TRISFbits.TRISF6   = 1;
}

void i2c_send(void)
{
    I2CEnable(1, TRUE);
    I2CSetFrequency(1, F_PB, 100000);
    I2CStart(1);
    I2CSendByte(1, (BME280_ADDRESS << 1) | 0);
    while (!I2CTransmissionHasCompleted(1));
    while (!I2CByteWasAcknowledged(1));
    I2CSendByte(1, 0xFC);
    while (!I2CTransmissionHasCompleted(1));
    while (!I2CByteWasAcknowledged(1));
    I2CRepeatStart(1);
    I2CSendByte(1, (BME280_ADDRESS << 1) | 1);
    while (!I2CTransmissionHasCompleted(1));
    while (!I2CByteWasAcknowledged(1));
    I2CReceiverEnable(1, TRUE);
}

void __attribute__((vector(_I2C1_VECTOR),interrupt(IPL3AUTO)))
     i2c_callback(void)
{
    return ;
}

void main(void)
{
    SYSTEMConfigPerformance(8000000);
    configure_ports();
    configure_realtime_clock();
    neopixels_begin(&LATB, 0, 60);
    setup_callbacks();
    i2c_send();
    while (1);
}
