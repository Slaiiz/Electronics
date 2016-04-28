/*
 * File:   disable.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

/*
 * libi2c_disable:
 * Switch off the given I2C module id.
 * This function may be called after a complete transaction.
 */

void    libi2c_disable(I2C_MODULE id)
{
    I2CEnable(id, FALSE);
}
