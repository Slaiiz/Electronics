/*
 * File:   read.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

UINT32  libi2c_read(I2C_MODULE id, UINT8 addr, UINT8* data, UINT32 n)
{
    I2C_RESULT  error;

    do {
        _libi2c_start(id);
        if ((error = _libi2c_send(id, (addr << 1) | 0)) != I2C_SUCCESS) {
            if (error == I2C_MASTER_BUS_COLLISION) {
                _libi2c_stop(id);
                continue ;
            }
        }
        while (n--)
            if ((error = _libi2c_send(id, *data++)) != I2C_SUCCESS)
                break ;
        if (error == I2C_MASTER_BUS_COLLISION) {
            _libi2c_stop(id);
            continue ;
        }
        while (!I2CTransmissionHasCompleted(id));
        _libi2c_stop(id);
        return (0);
    } while (1);
}
