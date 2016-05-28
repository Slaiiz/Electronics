/* 
 * File:   lcd.h
 * Author: bocal
 *
 * Created on 15 avril 2016, 19:12
 */

#ifndef LIBLCD_H
#define	LIBLCD_H

#include <xc.h>
#include <stdbool.h>
#include <GenericTypeDefs.h>

#define liblcd_mvputchr(a, b, c) do {liblcd_move((b), (c)); liblcd_putchr((a));} while(0);
#define liblcd_mvputstr(a, b, c) do {liblcd_move((b), (c)); liblcd_putstr((a));} while(0);

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

extern UINT8 _displayfunction;
extern UINT8 _displaycontrol;
extern UINT8 _displaymode;

extern UINT8 _curcol;
extern UINT8 _currow;
extern UINT8 _numrow;
extern UINT8 _numcol;

void    delay_micros(UINT32 us);

void    liblcd_autoscroll(bool on);
void    liblcd_begin(UINT8 col, UINT8 row);
void    liblcd_blink(bool on);
void    liblcd_clear(void);
void    liblcd_command(UINT8 cmd);
void    liblcd_cursor(bool on);
void    liblcd_display(bool on);
void    liblcd_home(void);
void    liblcd_light(UINT8 mode);
void    liblcd_move(UINT8 col, UINT8 row);
void    liblcd_pulse(void);
void    liblcd_putchr(UINT8 c);
void    liblcd_putstr(UINT8 *s);
void    liblcd_send(UINT8 value, UINT8 mode);

#endif	/* LCD_H */
