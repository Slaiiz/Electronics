/*
 * File:   _start.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

void    _libi2c_start(I2C_MODULE id)
{
    while (!I2CBusIsIdle(id));
    while (I2CStart(id) == I2C_MASTER_BUS_COLLISION)
        I2CStop(id);
}
