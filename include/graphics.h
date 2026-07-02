#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

typedef struct {
    int x;
    int y;
    int w;
    int h;
} rect_t;

extern const color_t COLOR_BACKGROUND;
extern const color_t COLOR_PANEL_BG;
extern const color_t COLOR_PANEL_BORDER;
extern const color_t COLOR_TEXT_PRIMARY;
extern const color_t COLOR_TEXT_SECONDARY;
extern const color_t COLOR_ACCENT_PURPLE;
extern const color_t COLOR_ACCENT_PURPLE_DARK;
extern const color_t COLOR_PROGRESS_BG;
extern const color_t COLOR_SEPARATOR;

void graphics_init(void);
void graphics_shutdown(void);
void graphics_clear(void);
void graphics_flip(void);
void draw_panel(rect_t area, const char *title);
void draw_text(int x, int y, const char *text, color_t color, float scale);
void draw_progress_bar(rect_t area, float percent, color_t fill_color, color_t bg_color);
void draw_separator(int x, int y, int width, color_t color);
void draw_highlight_box(rect_t area, color_t color);
void draw_footer(const char *hint_text);

#endif 