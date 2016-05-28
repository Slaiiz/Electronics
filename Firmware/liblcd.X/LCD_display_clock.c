#include "lcd.h"

void    LCD_display_clock(UINT32 y, UINT32 M, UINT32 d, UINT32 wd, UINT32 h, UINT32 m, UINT32 s)
{
    char *days[7];
    days[0] = "DIM";
    days[1] = "LUN";
    days[2] = "MAR";
    days[3] = "MER";
    days[4] = "JEU";
    days[5] = "VEN";
    days[6] = "SAM";

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

    LCD_setCursor(1, 1);
    LCD_putstr(days[wd]);
    LCD_putchar(' ');
    LCD_putchar('0' + d / 10);
    LCD_putchar('0' + d % 10);
    LCD_putchar('/');
    LCD_putchar('0' + M / 10);
    LCD_putchar('0' + M % 10);
    LCD_putchar('/');
    LCD_putchar('2');
    LCD_putchar('0');
    LCD_putchar('0' + y / 10);
    LCD_putchar('0' + y % 10);
}