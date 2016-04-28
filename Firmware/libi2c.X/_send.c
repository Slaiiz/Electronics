/*
 * File:   send.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#include "libi2c.h"

I2C_RESULT  _libi2c_send(I2C_MODULE id, UINT32 byte)
{
    I2C_RESULT  error;

    while (!I2CTransmitterIsReady(id));
    if ((error = I2CSendByte(id, byte)) != I2C_SUCCESS)
        return (error);
    if (!I2CByteWasAcknowledged(id))
        return (I2C_ERROR);
    return (I2C_SUCCESS);
}
