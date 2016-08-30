<<<<<<< HEAD
=======
/*
 * File:   write.c
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
#include "libi2c.h"

/*
 * libi2c_write:
 * Send a complete write request to a given I2C slave module responding to
 * address 'addr'. The request shall be encoded in an array of UINT8 pointed
 * at by 'data' according to the specifications of your slave module,
 * with 'n' indicating the size in bytes of your request.
 * This function was not designed for reading data from a slave. For that
 * purpose, use the libi2c_read() function instead.
 */

<<<<<<< HEAD
void    libi2c_write(e_i2c id, uint8_t addr, uint8_t *data, uint32_t n)
{
retry:
    while (true) {
        _libi2c_start(id);
        if (!_libi2c_send(id, (addr << 1) | 0))
            continue ;
        while (n--)
            if (!_libi2c_send(id, *data++))
                goto retry;
        _libi2c_stop(id);
        return ;
=======
I2C_RESULT  libi2c_write(I2C_MODULE id, UINT8 addr, UINT8* data, UINT32 n)
{
    I2C_RESULT  error;
    UINT8       *copy;

    copy = data;
    while (1) {
        _libi2c_start(id);
        if ((error = _libi2c_send(id, (addr << 1) | 0)) != I2C_SUCCESS) {
            _libi2c_stop(id);
            if (error == I2C_MASTER_BUS_COLLISION)
                continue ;
            return (I2C_ERROR);
        }
        while (n--) {
            if ((error = _libi2c_send(id, *data++)) != I2C_SUCCESS) {
                _libi2c_stop(id);
                if (error == I2C_MASTER_BUS_COLLISION)
                    break ;
                return (I2C_ERROR);
            }
        }
        if (error == I2C_MASTER_BUS_COLLISION)
            continue ;
        _libi2c_stop(id);
        return (I2C_SUCCESS);
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
    }
}
