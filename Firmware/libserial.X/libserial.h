/* 
 * File:   libserial.h
 * Author: bocal
 *
 * Created on 23 mai 2016, 18:06
 */

#ifndef LIBSERIAL_H
#define	LIBSERIAL_H

#include <xc.h>
#include <GenericTypeDefs.h>

UINT8   libserial_available(void);
void    libserial_begin(UINT16 speed);
UINT32  libserial_getstr(UINT8 *str);
UINT8   libserial_getchr();
void    libserial_putchr(UINT8 ch);
void    libserial_putstr(UINT8 *str);

void    delay_micros(UINT32 micros);
void    delay_millis(UINT32 millis);

#endif	/* LIBSERIAL_H */
