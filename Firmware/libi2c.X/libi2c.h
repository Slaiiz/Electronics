/* 
 * File:   libi2c.h
 * Author: vchesnea
 *
 * Created on April 28, 2016, 1:41 PM
 */

#ifndef LIBI2C_H
#define	LIBI2C_H

<<<<<<< HEAD
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "libsys.h"

/* Enumerations */

typedef enum {
    I2C1,
    I2C2
} e_i2c;
=======
#include <GenericTypeDefs.h>
#include <peripheral/i2c.h>
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b

typedef enum {
    STANDARD  =  100000,
    FAST      =  400000,
    HIGHSPEED = 1000000
<<<<<<< HEAD
} e_i2cmode;

/* Type definitions */

typedef struct {
    uint32_t    reg;
    uint32_t    clr;
    uint32_t    set;
    uint32_t    inv;
} s_reg;

typedef struct {
    s_reg       con;
    s_reg       stat;
    s_reg       add;
    s_reg       msk;
    s_reg       brg;
    s_reg       trn;
    s_reg       rcv;
} s_i2c;

s_i2c   *_i2c_base[] = {
    _I2C1_BASE_ADDRESS,
    _I2C2_BASE_ADDRESS
};

/* Function prototypes */

void    libi2c_disable(e_i2c id);
void    libi2c_enable(e_i2c id, e_i2cmode mode);
void    libi2c_read(e_i2c id, uint8_t addr, uint8_t reg, uint8_t *data, uint32_t n);
void    libi2c_write(e_i2c id, uint8_t addr, uint8_t *data, uint32_t n);

bool    _libi2c_send(e_i2c id, uint8_t byte);
bool    _libi2c_start(e_i2c id);
void    _libi2c_stop(e_i2c id);

#endif
=======
} e_mode;

void        libi2c_enable(I2C_MODULE id, e_mode mode);
void        libi2c_disable(I2C_MODULE id);

I2C_RESULT  libi2c_write(I2C_MODULE id, UINT8 addr, UINT8* data, UINT32 n);
I2C_RESULT  libi2c_read(I2C_MODULE id, UINT8 addr, UINT8 reg, UINT8* data);

void        _libi2c_start(I2C_MODULE id);
void        _libi2c_stop(I2C_MODULE id);
I2C_RESULT  _libi2c_send(I2C_MODULE id, UINT32 byte);

#endif	/* LIBI2C_H */
>>>>>>> ea9453d994e05eef8d2313677149b43b0a164d7b
