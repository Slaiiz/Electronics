/*
 * File:   read.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

/*
 * libi2c_read:
 * Send a complete read request to a given I2C slave responding to address
 * 'addr', for reading from slave's register address 'reg' and return
 * the result in 'data'. This function is able to read one byte only per call.
 */

I2C_RESULT  libi2c_read(I2C_MODULE id, UINT8 addr, UINT8 reg, UINT8* data)
{
    I2C_RESULT  error;

    while (1) {
        _libi2c_start(id);
        if ((error = _libi2c_send(id, (addr << 1) | 0)) != I2C_SUCCESS) {
            _libi2c_stop(id);
            if (error == I2C_MASTER_BUS_COLLISION)
                continue ;
            return (I2C_ERROR);
        }
        if ((error = _libi2c_send(id, reg)) != I2C_SUCCESS) {
            _libi2c_stop(id);
            if (error == I2C_MASTER_BUS_COLLISION)
                continue ;
            return (I2C_ERROR);
        }
        while (I2CRepeatStart(id) != I2C_SUCCESS);
        if ((error = _libi2c_send(id, (addr << 1) | 1)) != I2C_SUCCESS) {
            _libi2c_stop(id);
            if (error == I2C_MASTER_BUS_COLLISION)
                continue ;
            return (I2C_ERROR);
        }
        I2CReceiverEnable(id, TRUE);
        while (!I2CReceivedDataIsAvailable(id));
        I2CAcknowledgeByte(id, FALSE);
        *data = I2CGetByte(id);
        _libi2c_stop(id);
        return (I2C_SUCCESS);
    }
}
