/* 
 * File:   libi2c.h
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#ifndef LIBI2C_H
#define	LIBI2C_H

#include <peripheral/i2c.h>

typedef enum {
    STANDARD  =  100000,
    FAST      =  400000,
    HIGHSPEED = 1000000
} e_mode;

extern UINT32** i2cBase;

void        libi2c_enable(I2C_MODULE id, e_mode mode);
void        libi2c_disable(I2C_MODULE id);

UINT32      libi2c_write(I2C_MODULE id, UINT8 addr, UINT8* data, UINT32 n);
UINT32      libi2c_read(I2C_MODULE id, UINT8 addr, UINT8* data, UINT32 n);

void        _libi2c_start(I2C_MODULE id);
void        _libi2c_stop(I2C_MODULE id);
I2C_RESULT  _libi2c_send(I2C_MODULE id, UINT32 byte);

#endif	/* LIBI2C_H */
