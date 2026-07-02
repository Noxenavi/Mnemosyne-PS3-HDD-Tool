#include <stddef.h>
#include "menu.h"
#include "graphics.h"

static const menu_item_t menu_items[MENU_ITEM_COUNT] = {
    { MENU_DASHBOARD,        "Dashboard" },
    { MENU_STORAGE_ANALYZER, "Storage Analyzer" },
    { MENU_FILE_BROWSER,     "File Browser" },
    { MENU_GAMES,            "Games" },
    { MENU_SAVE_DATA,        "Save Data" },
    { MENU_PACKAGES,         "Packages" },
    { MENU_CLEANUP,          "Cleanup" },
    { MENU_SETTINGS,         "Settings" },
    { MENU_ABOUT,            "About" },
};

#define MENU_ITEM_HEIGHT 34

void menu_init(menu_state_t *menu)
{
    if (menu == NULL) return;
    menu->selected_index = MENU_DASHBOARD;
}

void menu_navigate(menu_state_t *menu, int direction)
{
    if (menu == NULL) return;

    int new_index = menu->selected_index + direction;

    if (new_index < 0) {
        new_index = 0;
    } else if (new_index >= MENU_ITEM_COUNT) {
        new_index = MENU_ITEM_COUNT - 1;
    }

    menu->selected_index = new_index;
}

menu_item_id_t menu_get_selected(const menu_state_t *menu)
{
    if (menu == NULL) return MENU_DASHBOARD;
    return menu_items[menu->selected_index].id;
}

void menu_draw(const menu_state_t *menu, rect_t area)
{
    if (menu == NULL) return;

    draw_text(area.x, area.y, "Mnemosyne", COLOR_ACCENT_PURPLE, 1.2f);
    draw_text(area.x, area.y + 20, "HDD Tool", COLOR_TEXT_PRIMARY, 1.2f);

    int list_start_y = area.y + 70; /* espaço reservado para o logo */

    for (int i = 0; i < MENU_ITEM_COUNT; i++) {
        rect_t item_area = {
            area.x,
            list_start_y + (i * MENU_ITEM_HEIGHT),
            area.w,
            MENU_ITEM_HEIGHT
        };

        color_t label_color = COLOR_TEXT_PRIMARY;

        if (i == menu->selected_index) {
            draw_highlight_box(item_area, COLOR_ACCENT_PURPLE);
            label_color = COLOR_TEXT_PRIMARY;
        }

        draw_text(item_area.x + 12, item_area.y + 8,
                   menu_items[i].label, label_color, 1.0f);
    }
}
