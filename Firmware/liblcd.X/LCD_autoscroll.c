#include "lcd.h"

void    LCD_autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  LCD_command(LCD_ENTRYMODESET | _displaymode);
}