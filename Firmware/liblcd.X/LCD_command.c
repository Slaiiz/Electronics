#include "lcd.h"

void    LCD_command(UINT8 com)
{
    LCD_send(com, 0);
}