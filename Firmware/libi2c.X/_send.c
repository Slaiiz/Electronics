<<<<<<< HEAD
#include "libi2c.h"

bool    _libi2c_send(e_i2c id, uint8_t byte)
{
    s_i2c   *i2c = (s_i2c*)_i2c_base[id];

    while (i2c->stat.reg & _I2C1STAT_TBF_MASK);
    i2c->trn.reg = byte;
    if (i2c->stat.reg & (_I2C1STAT_IWCOL_MASK | _I2C1STAT_BCL_MASK))
        return (false);
    while (i2c->stat.reg & _I2C1STAT_TRSTAT_MASK);
    return (!(i2c->stat.reg & _I2C1STAT_ACKSTAT_MASK));
=======
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
    while (!I2CTransmissionHasCompleted(id));
    if (!I2CByteWasAcknowledged(id))
        return (I2C_ERROR);
    return (I2C_SUCCESS);
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
}
