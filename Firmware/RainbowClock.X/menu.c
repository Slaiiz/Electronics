#include "rainbowclock.h"

uint8_t *months[12] = {
    "JAN", "FEV", "MAR", "AVR", "MAI", "JUN",
    "JUI", "AOU", "SEP", "OCT", "NOV", "DEC" };
uint8_t *days[7] = {
    "DIMANCHE", "LUNDI", "MARDI", "MERCREDI",
    "JEUDI", "VENDREDI", "SAMEDI" };

static void display_short_time(void)
{
    liblcd_moveputn(lcd, 0, 0, date.day, 10, 2);
    liblcd_putc(lcd, '/');
    liblcd_putn(lcd, date.month, 10, 2);
    liblcd_putc(lcd, '/');
    liblcd_putn(lcd, date.year, 10, 4);
    liblcd_moveputn(lcd, 12, 0, date.hours, 10, 2);
    liblcd_putc(lcd, ':');
    liblcd_putn(lcd, date.minutes, 10, 2);
    liblcd_putc(lcd, ':');
    liblcd_putn(lcd, date.seconds, 10, 2);
}

static void display_long_time(void)
{
    liblcd_moveputs(lcd, 0, 0, days[date.day_of_week - 1]);
    liblcd_moveputn(lcd, 9, 0, date.day, 10, 2);
    liblcd_moveputs(lcd, 12, 0, months[date.month - 1]);
    liblcd_moveputn(lcd, 16, 0, date.year, 10, 4);
    liblcd_moveputn(lcd, 6, 2, date.hours, 10, 2);
    liblcd_putc(lcd, ':');
    liblcd_putn(lcd, date.minutes, 10, 2);
    liblcd_putc(lcd, ':');
    liblcd_putn(lcd, date.seconds, 10, 2);
}

static void draw_template_main(MENU *menu, LCD *lcd)
{
    display_long_time();
}

static void draw_template_plain(MENU *menu, LCD *lcd)
{
    liblcd_moveputs(lcd, 8, 0, "\xA5 \xA5");
    liblcd_moveputs(lcd, 8, 1, "'^");
    liblcd_moveputs(lcd, 0, 2, "We ran out of memory");
    liblcd_moveputs(lcd, 2, 3, "for this feature");
}

static void draw_template_vertical(MENU *menu, LCD *lcd)
{
    ITEM    *item;

    display_short_time();
    if ((item = menu->curr)) {
        if (item->prev) {
            liblcd_move(lcd, (20 - strlen(item->prev->name)) / 2, 3);
            liblcd_puts(lcd, item->prev->name);
        }
        liblcd_moveputs(lcd, 0, 2, ">                  <");
        liblcd_move(lcd, (20 - strlen(item->name)) / 2, 2);
        liblcd_puts(lcd, item->name);
        if (item->next) {
            liblcd_move(lcd, (20 - strlen(item->next->name)) / 2, 1);
            liblcd_puts(lcd, item->next->name);
        }
    }
}

static void draw_template_horizontal(MENU *menu, LCD *lcd)
{
    ITEM    *item;

    display_short_time();
    if ((item = menu->curr)) {
        liblcd_moveputc(lcd,  0, 1, item->prev ? '\x7F' : ' ');
        liblcd_moveputc(lcd, 19, 1, item->next ? '\x7E' : ' ');
        liblcd_move(lcd, (20 - strlen(item->name)) / 2, 1);
        liblcd_puts(lcd, item->name);
        liblcd_moveputs(lcd, 0, 2, "--------------------");
        liblcd_moveputs(lcd, 0, 3, item->desc);
    }
}

void        menu_add_item(MENU *menu, ITEM *item)
{
    ITEM **curr, **prev;

    prev = NULL;
    curr = &menu->items;
    while (*curr != NULL) {
        prev = curr;
        curr = &(*curr)->next;
    }
    if (prev != NULL)
        item->prev = *prev;
    if (menu->curr == NULL)
        menu->curr = item;
    if (item->type == ITEM_LINK)
        ((MENU*)item->data)->parent = menu;
    *curr = item;
}

bool        menu_new_item(ITEM **out, e_itemtype type, DESC desc, void *data)
{
    ITEM    *item;

    if ((*out = malloc(sizeof(**out))) == NULL)
        return (false);
    item = *out;
    memset(item, 0x00, sizeof(**out));
    item->name = desc.name;
    item->desc = desc.desc;
    item->type = type;
    item->data = data;
    return (true);
}

void        menu_delete_item(ITEM **item)
{
    ITEM    *tmp;

    tmp = *item;
    if (tmp->prev && tmp->next) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    free(tmp);
    *item = NULL;
}

bool        menu_new(MENU **out, e_menutype type)
{
    if ((*out = malloc(sizeof(**out))) == NULL)
        return (false);
    memset(*out, 0x00, sizeof(**out));
    (*out)->type = type;
    return (true);
}

void        menu_delete(MENU **menu)
{
    free(*menu);
    *menu = NULL;
}

void        menu_update(MENU *menu, LCD *lcd)
{
    liblcd_clear(lcd);
    switch (menu->type) {
        case MENU_MAIN:
            draw_template_main(menu, lcd);
            break ;
        case MENU_VERTICAL:
            draw_template_vertical(menu, lcd);
            break ;
        case MENU_HORIZONTAL:
            draw_template_horizontal(menu, lcd);
            break ;
        case MENU_PLAIN:
            draw_template_plain(menu, lcd);
            break ;
    }
}
