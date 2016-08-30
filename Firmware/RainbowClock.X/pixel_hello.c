#include "rainbowclock.h"

void    pixel_hello(void)
{
    uint32_t    status, i;

    asm volatile ("di %0": "=r" (status));
    libpixel_clear(pixels);
    for (i = 0; i < 60; ++i) {
        libpixel_set(pixels, i, 32, 0, 0);
        libpixel_show(pixels);
        libsys_delay_millis(100);
    }
    for (i = 0; i < 60; ++i)
        libpixel_set(pixels, i, 0, 32, 0);
    libpixel_show(pixels);
    libsys_delay(1);
    libpixel_clear(pixels);
    libpixel_show(pixels);
    if (status)
        asm volatile ("ei");
}
