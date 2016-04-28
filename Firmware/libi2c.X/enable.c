/*
 * File:   enable.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

UINT32  pllidiv[8] = {1, 2, 3, 4, 5, 6, 10, 12};
UINT32  pllodiv[8] = {1, 2, 4, 8, 16, 32, 64, 256};
UINT32  pllmult[8] = {15, 16, 17, 18, 19, 20, 21, 24};

void    libi2c_enable(I2C_MODULE id, e_mode mode)
{
    UINT32  freq;

    switch (OSCCONbits.COSC) {
        case 0b000: // FRC
        case 0b010: // PRI
            freq = 8000000;
            break ;
        case 0b001: // FRCPLL
        case 0b011: // PRIPLL
            freq /= pllidiv[(DEVCFG2 >>  0) & 7];
            freq *= pllmult[(DEVCFG2 >>  4) & 7];
            freq /= pllodiv[(DEVCFG2 >> 16) & 7];
            break ;
    }
    I2CSetFrequency(id, freq, mode);
    I2CEnable(id, TRUE);
}
