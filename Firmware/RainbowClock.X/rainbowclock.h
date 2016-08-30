#ifndef RAINBOWCLOCK_H
#define	RAINBOWCLOCK_H

#include <xc.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "libsys.h"
#include "liblcd.h"
#include "libuart.h"
#include "libpixel.h"

#include "menu.h"

/* Definitions */

#define ISR(vec,pri)    __attribute__((vector(vec),interrupt(pri),nomips16))
#define ENCODER_DELAY   10

/* Enumerations */

typedef enum {
    BUTTON_NONE,
    BUTTON_ENTER,
    BUTTON_CANCEL
} e_button;

typedef enum {
    ENCODER_NONE,
    ENCODER_PREVIOUS,
    ENCODER_NEXT
} e_encoder;

/* Type definitions */

typedef struct {
    uint16_t r;
    uint16_t g;
    uint16_t b;
} COLOR;

typedef struct {
    COLOR   bg;
    COLOR   mk;
    COLOR   hr;
    COLOR   mn;
    COLOR   sc;
} SCHEME;

typedef struct {
    uint8_t  day_of_week;
    uint16_t millis;
    uint16_t seconds;
    uint16_t minutes;
    uint16_t hours;
    uint8_t  day;
    uint8_t  month;
    uint16_t year;
} DATE;


/* Function prototypes */

uint8_t     bcd_to_dec(uint8_t n);
uint8_t     dec_to_bcd(uint8_t n);
bool        initialize_system(void);
uint8_t     tondering_day_of_week(void);

void        crash_clock(void);
void        pixel_hello(void);
void        reset_clock(void);
void        say_hello(void);
void        toggle_lcd(void);

/* External references */

extern LCD      *lcd;
extern SCHEME   color;
extern MENU     *menu;
extern PIXEL    *pixels;
extern DATE     date;

#endif
