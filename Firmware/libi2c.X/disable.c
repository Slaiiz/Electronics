<<<<<<< HEAD
#include "libi2c.h"

void    libi2c_disable(e_i2c id)
{
    s_i2c   *i2c = (s_i2c*)_i2c_base[id];

    i2c->con.clr = _I2C1CON_ON_MASK;
=======
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
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
}
