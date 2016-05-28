#include "lcd.h"

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