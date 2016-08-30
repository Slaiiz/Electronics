/* TODO:
 * - Rewrite libpixel  OK
 * - Rewrite libuart   OK
 * - Rewrite liblcd    OK
 * - Rewrite libi2c    ??
 */

#include "rainbowclock.h"

DATE    date;
LCD     *lcd;
MENU    *menu;
PIXEL   *pixels;

static e_button  poll_buttons(void)
{
    bool        n_enter, n_cancel;
    static bool o_enter, o_cancel;
    e_button    out = BUTTON_NONE;

    if ((n_enter = PORTCbits.RC4) && !o_enter)
        out = BUTTON_ENTER;
    else if ((n_cancel = PORTCbits.RC3) && !o_cancel)
        out = BUTTON_CANCEL;
    libsys_delay_millis(5); /* Workaround for push button hysteresis*/
    o_cancel = n_cancel;
    o_enter  = n_enter;
    return (out);
}

static e_encoder poll_encoder(void)
{
    uint8_t     i;
    bool        state_b;
    bool        state_c;
    static bool old_state_b;
    static bool old_state_c;
    e_encoder   out = ENCODER_NONE;

    state_b = PORTBbits.RB7;
    state_c = PORTCbits.RC8;
    if (state_b != old_state_b) {
        while (state_b != PORTCbits.RC8 && i < ENCODER_DELAY)
            i++;
        if (i < ENCODER_DELAY)
            out = ENCODER_PREVIOUS;
    }
    else if (state_c != old_state_c) {
        while (state_c != PORTBbits.RB7 && i < ENCODER_DELAY)
            i++;
        if (i < ENCODER_DELAY)
            out = ENCODER_NEXT;
    }
    old_state_b = state_b;
    old_state_c = state_c;
    return (out);
}

static void      poll_command(void)
{
    uint8_t  c, *s, b[8];

    if (libuart_getc(UART1, &c) && c == 'T')
    {
        libuart_gets(UART1, &s);
        date.seconds = 10 * (s[0]  - '0') + s[1]  - '0';
        date.minutes = 10 * (s[2]  - '0') + s[3]  - '0';
        date.hours   = 10 * (s[4]  - '0') + s[5]  - '0';
        date.day     = 10 * (s[6]  - '0') + s[7]  - '0';
        date.month   = 10 * (s[8]  - '0') + s[9]  - '0';
        date.year    = 1000 * (s[10] - '0') + 100 * (s[11] - '0') + 10 * (s[12] - '0') + (s[13] - '0');
        date.day_of_week = tondering_day_of_week();
        libuart_puts(UART1, "Ok!\n");
        free(s);
    }
}

static void      processing_queue(void)
{
    e_button    button;
    e_encoder   encoder;

    while (true) {
        if ((button = poll_buttons())) {
            if (button == BUTTON_ENTER && menu->curr) {
                switch (menu->curr->type) {
                    case ITEM_HOOK:
                        ((void(*)(void))menu->curr->data)();
                        break ;
                    case ITEM_LINK:
                        if (menu->curr->data) {
                            menu = (MENU*)menu->curr->data;
                            menu_update(menu, lcd);
                        }
                        break ;
                    default:
                        break ;
                }
            } else if (button == BUTTON_CANCEL) {
                if (menu->parent) {
                    menu = menu->parent;
                    menu_update(menu, lcd);
                }
            }
        }
        if ((encoder = poll_encoder()) && menu->curr) {
            if (encoder == ENCODER_PREVIOUS && menu->curr->prev) {
                menu->curr = menu->curr->prev;
                menu_update(menu, lcd);
            } else if (encoder == ENCODER_NEXT && menu->curr->next) {
                menu->curr = menu->curr->next;
                menu_update(menu, lcd);
            }
        }
        poll_command();
        WDTCONbits.WDTCLR = 1; /* Give periodic life signs to the watchdog */
    }
}

void             main(void)
{
    initialize_system();
    menu_update(menu, lcd);
    processing_queue();
}
