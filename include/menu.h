#ifndef MENU_H
#define MENU_H

#include "graphics.h"

typedef enum {
    MENU_DASHBOARD = 0,
    MENU_STORAGE_ANALYZER,
    MENU_FILE_BROWSER,
    MENU_GAMES,
    MENU_SAVE_DATA,
    MENU_PACKAGES,
    MENU_CLEANUP,
    MENU_SETTINGS,
    MENU_ABOUT,
    MENU_ITEM_COUNT 
} menu_item_id_t;
typedef struct {
    menu_item_id_t id;
    const char *label;
} menu_item_t;
typedef struct {
    int selected_index;
} menu_state_t;
void menu_init(menu_state_t *menu);
void menu_navigate(menu_state_t *menu, int direction);
menu_item_id_t menu_get_selected(const menu_state_t *menu);
void menu_draw(const menu_state_t *menu, rect_t area);

#endif 

