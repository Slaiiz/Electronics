/* 
 * File:   lcd.h
 * Author: bocal
 *
 * Created on 15 avril 2016, 19:12
 */

#ifndef LCD_H
#define	LCD_H

#include <xc.h>
#include <GenericTypeDefs.h>

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

void    delay_micros(UINT32 ms);
void    LCD_autoscroll(void);
void    LCD_begin(UINT8 col, UINT8 row);
void    LCD_blink(void);
void    LCD_clear(void);
void    LCD_command(UINT8 com);
void    LCD_cursor(void);
void    LCD_display(void);
void    LCD_display_clock(UINT32 y, UINT32 M, UINT32 d, UINT32 wd, UINT32 h, UINT32 m, UINT32 s);
void    LCD_home(void);
void    LCD_Light(UINT8 mode);
void    LCD_noAutoscroll(void);
void    LCD_noBlink(void);
void    LCD_noCursor(void);
void    LCD_nodisplay(void);
void    LCD_pin_reset(void);
void    LCD_pulseE(void);
void    LCD_putchar(UINT8 car);
void    LCD_putstr(UINT8 *str);
void    LCD_putstrPos(UINT8 *str, UINT8 col, UINT8 row);
void    LCD_send(UINT8 value, UINT8 mode);
void    LCD_setCursor(UINT8 col, UINT8 row);

#endif	/* LCD_H */

