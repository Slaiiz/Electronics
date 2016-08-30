<<<<<<< HEAD
#include "libi2c.h"

void    _libi2c_stop(e_i2c id)
{
    s_i2c   *i2c = (s_i2c*)_i2c_base[id];

    i2c->con.set = _I2C1CON_PEN_MASK;
=======
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
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
}
