<<<<<<< HEAD
=======
/*
 * File:   read.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
#include "libi2c.h"

/*
 * libi2c_read:
 * Send a complete read request to a given I2C slave responding to address
<<<<<<< HEAD
 * 'addr', reading from slave's register address 'reg', and return 'n' bytes of
 * data in 'data'.
 */

void    libi2c_read(e_i2c id, uint8_t addr, uint8_t reg, uint8_t *data, uint32_t n)
{
    s_i2c   *i2c = (s_i2c*)_i2c_base[id];

    while (true) {
        _libi2c_start(id);
        if (!_libi2c_send(id, (addr << 1) | 0) || !_libi2c_send(id, reg))
            continue ;
        _libi2c_stop(id);
        if (!_libi2c_send(id, (addr << 1) | 1))
            continue ;
        i2c->con.set = _I2C1CON_RCEN_MASK;
        while (n--) {
            while (!i2c->stat.reg & _I2C1STAT_RBF_MASK);
            if (n && 1)
                i2c->con.clr = _I2C1CON_ACKDT_MASK;
            else
                i2c->con.set = _I2C1CON_ACKDT_MASK;
            i2c->con.set = _I2C1CON_ACKEN_MASK;
            *data++ = i2c->rcv.reg;
        }
        _libi2c_stop(id);
        return ;
=======
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
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
    }
}
