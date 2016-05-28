#include "lcd.h"

UINT8 _displayfunction = 0;
UINT8 _displaycontrol = 0;
UINT8 _displaymode = 0;
UINT8 _curcol = 0;
UINT8 _currow = 0;
UINT8 _numrow = 0;
UINT8 _numcol = 0;

void    LCD_Light(UINT8 mode)
{
    LATFbits.LATF5 = mode;
}

void    delay_micros(UINT32 ms)
{
    while (ms)
    {
        ms--;
    }
}

void    LCD_pin_reset()
{
    TRISF   = 0;
    TRISD   = 0;
    LATD    = 0;
    TRISE   = 0;
    LATE    = 0;
}

void    LCD_nodisplay()
{
    _displaycontrol &= ~LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void    LCD_display()
{
    _displaycontrol |= LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void    LCD_noCursor() {
    _displaycontrol &= ~LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void    LCD_cursor() {
    _displaycontrol |= LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void    LCD_noBlink() {
    _displaycontrol &= ~LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void    LCD_blink() {
    _displaycontrol |= LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void    LCD_autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void    LCD_noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  LCD_command(LCD_ENTRYMODESET | _displaymode);
}

void    LCD_pulseE()
{
    LATEbits.LATE7 = 0;
    delay_micros(1); //1
    LATEbits.LATE7 = 1;
    delay_micros(1); //1
    LATEbits.LATE7 = 0;
    delay_micros(100); //100
}

void    LCD_setCursor(UINT8 col, UINT8 row)
{
  int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
  if ( row > _numrow ) {
    row = _numrow-1;    // we count rows starting w/0
  }

  LCD_command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
  _curcol = col;
  _currow = row;
}

void    LCD_putchar(UINT8 car)
{
    LCD_send(car, 1);
    _curcol++;
}

int     LCD_putstr(UINT8 *str)
{
    UINT32 i;
    i = 0;
    while (str[i] && (i < (_numcol * _numrow)))
    {
        if ((_curcol >= _numcol || str[i] == '\n'))
        {
            if (_currow < _numrow)
                LCD_setCursor(0, _currow + 1);
            if (str[i] == '\n')
                i++;
        }
        LCD_putchar(str[i]);
        i++;
    }
}

int     LCD_putstrPos(UINT8 *str, UINT8 col, UINT8 row)
{
    LCD_setCursor(col, row);
    LCD_putstr(str);
}

void    LCD_send(UINT8 value, UINT8 mode)
{
    LCD_pin_reset();
    LATEbits.LATE6      = mode;
    LATDbits.LATD4     = (value % 2);
    value /= 2;
    LATDbits.LATD5     = (value % 2);
    value /= 2;
    LATDbits.LATD6     = (value % 2);
    value /= 2;
    LATDbits.LATD7     = (value % 2);
    value /= 2;
    LATDbits.LATD10     = (value % 2);
    value /= 2;
    LATDbits.LATD11     = (value % 2);
    value /= 2;
    LATEbits.LATE0      = (value % 2);
    value /= 2;
    LATEbits.LATE3      = (value % 2);
    LCD_pulseE();
}

void    LCD_command(UINT8 com)
{
    LCD_send(com, 0);
}

void    LCD_home()
{
    LCD_command(LCD_RETURNHOME);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}

void    LCD_clear()
{
    LCD_command(LCD_CLEARDISPLAY);
    delay_micros(2000);
    _curcol = 0;
    _currow = 0;
}

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

void    LCD_display_clock(UINT32 y, UINT32 M, UINT32 d, UINT32 wd, UINT32 h, UINT32 m, UINT32 s)
{
    LCD_clear();
    LCD_setCursor(4, 0);
    LCD_putchar('0' + h / 10);
    LCD_putchar('0' + h % 10);
    LCD_putchar(':');
    LCD_putchar('0' + m / 10);
    LCD_putchar('0' + m % 10);
    LCD_putchar(':');
    LCD_putchar('0' + s / 10);
    LCD_putchar('0' + s % 10);

    LCD_setCursor(0, 1);
    LCD_putchar('0' + wd);
    LCD_putchar(' ');
    LCD_putchar('0' + d / 10);
    LCD_putchar('0' + d % 10);
    LCD_putchar('/');
    LCD_putchar('0' + M / 10);
    LCD_putchar('0' + M % 10);
    LCD_putchar('/');
    LCD_putchar('0' + y / 10);
    LCD_putchar('0' + y % 10);
}

