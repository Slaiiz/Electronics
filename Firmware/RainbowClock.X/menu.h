#ifndef MENU_H
#define	MENU_H

/* Enumerations */

typedef enum {
    ITEM_TEXT,
    ITEM_HOOK,
    ITEM_LINK,
    ITEM_EDIT
} e_itemtype;

typedef enum {
    MENU_PLAIN,
    MENU_MAIN,
    MENU_VERTICAL,
    MENU_HORIZONTAL
} e_menutype;

/* Type definitions */

typedef struct s_desc {
    uint8_t const *name;
    uint8_t const *desc;
} DESC;

typedef struct s_text {
    uint8_t       x;
    uint8_t       y;
    uint8_t       *value;
} TEXT;

typedef struct s_hook {
    void          *addr;
} HOOK;

typedef struct s_link {
    void          *addr;
} LINK;

typedef struct s_edit {
    uint8_t       x;
    uint8_t       y;
    uint32_t      value;
    uint32_t      size;
    uint32_t      min;
    uint32_t      max;
} EDIT;

typedef struct s_item {
    uint8_t const *name;
    uint8_t const *desc;
    struct s_item *next;
    struct s_item *prev;
    void          *data;
    e_itemtype    type;
} ITEM;

typedef struct s_menu {
    e_menutype    type;
    ITEM          *curr;
    ITEM          *items;
    struct s_menu *parent;
} MENU;

void    menu_add_item(MENU *menu, ITEM *item);
void    menu_delete(MENU **menu);
void    menu_delete_item(ITEM **item);
bool    menu_new(MENU **out, e_menutype type);
bool    menu_new_item(ITEM **out, e_itemtype type, DESC desc, void *data);
void    menu_update(MENU *menu, LCD *lcd);

#endif
