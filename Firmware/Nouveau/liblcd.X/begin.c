#include "liblcd.h"

UINT8 _displayfunction;
UINT8 _displaycontrol;
UINT8 _displaymode;
UINT8 _curcol;
UINT8 _currow;
UINT8 _numrow;
UINT8 _numcol;

void    liblcd_begin(UINT8 col, UINT8 row)
{
    TRISDbits.TRISD4  = 0;
    TRISDbits.TRISD5  = 0;
    TRISDbits.TRISD6  = 0;
    TRISDbits.TRISD7  = 0;
    TRISDbits.TRISD10 = 0;
    TRISDbits.TRISD11 = 0;
    TRISEbits.TRISE0  = 0;
    TRISEbits.TRISE3  = 0;
    TRISEbits.TRISE6  = 0;
    TRISFbits.TRISF5  = 0;
    TRISEbits.TRISE7  = 0;

    delay_micros(50000);
    _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS | LCD_2LINE;
    liblcd_send(LCD_FUNCTIONSET | _displayfunction, 0);
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    delay_micros(4500);
    liblcd_display(true);
    liblcd_clear();
    liblcd_home();
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    liblcd_send(LCD_ENTRYMODESET | _displaymode, 0);
    _numrow = row;
    _numcol = col;
}
