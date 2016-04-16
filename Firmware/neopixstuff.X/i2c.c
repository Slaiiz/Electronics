/*
 * File:   i2c.c
 * Author: vchesnea
 *
 * Created on April 16, 2016, 4:59 PM
 */

//#include "rainbowclock.h"

void configure_i2c(unsigned int mode)
{
//    I2C1BRG = F_PB / (2 * mode) - 2;
//    I2C1CONbits.STRICT = 1;
//    I2C1CONbits.ON     = 1;
//    I2C1CONbits.PEN    = 1;
//    I2C1CONbits.RCEN   = 1;
}

long read_i2c(void)
{
//    I2C1CONbits.SEN    = 1;
}

void __attribute__((vector(25),interrupt(IPL3AUTO)))
     i2c_callback(void)
{
}
