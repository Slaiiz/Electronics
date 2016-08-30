#include "rainbowclock.h"

void    _general_exception_context(void)
{
    char     buffer[32];
    uint32_t var;

    liblcd_clear(lcd);
    liblcd_move(lcd, 0, 0);
    liblcd_puts(lcd, "Oops! That's a crash");
    liblcd_puts(lcd, "Prepare for a reboot");

    asm volatile ("mfc0 %0, $14": "=r" (var));
    utoa((char*)&buffer, (unsigned int)var, 16);
    liblcd_move(lcd, 0, 2);
    liblcd_puts(lcd, "EPC  : 0x");
    liblcd_puts(lcd, buffer);

    asm volatile ("mfc0 %0, $13": "=r" (var));
    utoa((char*)&buffer, (unsigned int)var, 16);
    liblcd_move(lcd, 0, 3);
    liblcd_puts(lcd, "Cause: 0x");
    liblcd_puts(lcd, buffer);

    libpixel_clear(pixels);
    for (var = 0; var < 60; ++var)
        libpixel_set(pixels, var, 15, 15 * (var & 1), 15 * (var & 1));
    libpixel_show(pixels);

    while (1);
}
