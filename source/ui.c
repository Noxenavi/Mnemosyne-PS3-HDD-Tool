#include <stddef.h>
#include "ui.h"
#include "graphics.h"
#include "dashboard.h"

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define TOPBAR_HEIGHT   70
#define SIDEBAR_WIDTH  260
#define FOOTER_HEIGHT   50

void ui_init(ui_state_t *ui)
{
    if (ui == NULL) return;

    graphics_init();
    menu_init(&ui->menu);
    dashboard_init();

    ui->running = 1;
}

static void draw_topbar(void)
{
    rect_t topbar_area = { 0, 0, SCREEN_WIDTH, TOPBAR_HEIGHT };

    draw_text(topbar_area.x + 20, topbar_area.y + 10,
               "Mnemosyne HDD Tool v0.1.0", COLOR_TEXT_PRIMARY, 1.1f);
    draw_text(topbar_area.x + 20, topbar_area.y + 32,
               "Storage Analysis & Management", COLOR_TEXT_SECONDARY, 1.0f);

    draw_text(topbar_area.x + topbar_area.w - 160, topbar_area.y + 18,
               "19/05 14:32", COLOR_TEXT_PRIMARY, 1.0f);

    draw_separator(0, TOPBAR_HEIGHT, SCREEN_WIDTH, COLOR_SEPARATOR);
}

void ui_update(ui_state_t *ui)
{
    if (ui == NULL) return;
}

void ui_draw(ui_state_t *ui)
{
    if (ui == NULL) return;

    graphics_clear();

    draw_topbar();

    rect_t sidebar_area = { 0, TOPBAR_HEIGHT + 20, SIDEBAR_WIDTH, SCREEN_HEIGHT - TOPBAR_HEIGHT - FOOTER_HEIGHT - 20 };
    menu_draw(&ui->menu, sidebar_area);

    rect_t content_area = {
        SIDEBAR_WIDTH + 20,
        TOPBAR_HEIGHT + 20,
        SCREEN_WIDTH - SIDEBAR_WIDTH - 40,
        SCREEN_HEIGHT - TOPBAR_HEIGHT - FOOTER_HEIGHT - 20
    };

    switch (menu_get_selected(&ui->menu)) {
        case MENU_DASHBOARD:
        default:
            dashboard_draw(content_area);
            break;
    }

    draw_footer("Press SELECT for options");

    graphics_flip();
}

void ui_shutdown(ui_state_t *ui)
{
    if (ui == NULL) return;
    graphics_shutdown();
    ui->running = 0;
}
