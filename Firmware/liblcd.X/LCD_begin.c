#include "lcd.h"

UINT8 _displayfunction = 0;
UINT8 _displaycontrol = 0;
UINT8 _displaymode = 0;
UINT8 _curcol = 0;
UINT8 _currow = 0;
UINT8 _numrow = 0;
UINT8 _numcol = 0;

void    LCD_begin(UINT8 col, UINT8 row)
{
    _numrow = row;
    _numcol = col;
    _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS;
    LCD_pin_reset();
    delay_micros(50000);
    _displayfunction |= LCD_2LINE;
    LCD_send(LCD_FUNCTIONSET | _displayfunction, 0);
    delay_micros(4500);
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    LCD_display();
    LCD_clear();
    LCD_home();
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    LCD_send(LCD_ENTRYMODESET | _displaymode, 0);
}