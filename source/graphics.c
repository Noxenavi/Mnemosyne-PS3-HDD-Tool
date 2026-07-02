#include <stdio.h>
#include "graphics.h"

const color_t COLOR_BACKGROUND        = {12, 8, 20, 255};
const color_t COLOR_PANEL_BG          = {20, 14, 32, 255};
const color_t COLOR_PANEL_BORDER      = {60, 45, 90, 255};
const color_t COLOR_TEXT_PRIMARY      = {235, 230, 245, 255};
const color_t COLOR_TEXT_SECONDARY    = {150, 140, 170, 255};
const color_t COLOR_ACCENT_PURPLE     = {124, 92, 210, 255};
const color_t COLOR_ACCENT_PURPLE_DARK= {80, 58, 140, 255};
const color_t COLOR_PROGRESS_BG       = {45, 38, 60, 255};
const color_t COLOR_SEPARATOR         = {50, 42, 68, 255};

void graphics_init(void)
{
}

void graphics_shutdown(void)
{
}

void graphics_clear(void)
{
}

void graphics_flip(void)
{
}

void draw_panel(rect_t area, const char *title)
{
    if (title != NULL) {
        draw_text(area.x, area.y, title, COLOR_ACCENT_PURPLE, 1.0f);
        draw_separator(area.x, area.y + 18, area.w, COLOR_SEPARATOR);
    }
}

void draw_text(int x, int y, const char *text, color_t color, float scale)
{
    (void)x; (void)y; (void)text; (void)color; (void)scale;
}

void draw_progress_bar(rect_t area, float percent, color_t fill_color, color_t bg_color)
{
    if (percent < 0.0f) percent = 0.0f;
    if (percent > 1.0f) percent = 1.0f;

    rect_t fill_area = area;
    fill_area.w = (int)(area.w * percent);

    (void)fill_area; (void)bg_color; (void)fill_color;
}

void draw_separator(int x, int y, int width, color_t color)
{
    (void)x; (void)y; (void)width; (void)color;
}

void draw_highlight_box(rect_t area, color_t color)
{
    (void)area; (void)color;
}

void draw_footer(const char *hint_text)
{
    draw_separator(0, 0, 0, COLOR_SEPARATOR);

    draw_text(0, 0, "X Enter", COLOR_TEXT_SECONDARY, 1.0f);
    draw_text(0, 0, "O Back", COLOR_TEXT_SECONDARY, 1.0f);

    if (hint_text != NULL) {
        draw_text(0, 0, hint_text, COLOR_TEXT_SECONDARY, 1.0f);
    }
}
