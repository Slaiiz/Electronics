/* 
 * File:   rainbowclock.h
 * Author: bocal
 *
 * Created on April 16, 2016, 2:40 PM
 */

#ifndef RAINBOWCLOCK_H
#define	RAINBOWCLOCK_H

#include <plib.h>
#include "confbits.h"
#include "libneopixels.h"

#warning LOL

#define BME280_ADDRESS  0x77

unsigned long   bcd_to_dec(unsigned long n);
void            configure_i2c(unsigned int mode);

#endif
