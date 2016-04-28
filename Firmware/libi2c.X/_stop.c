/*
 * File:   _stop.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

void    _libi2c_stop(I2C_MODULE id)
{
    I2CStop(id);
}
