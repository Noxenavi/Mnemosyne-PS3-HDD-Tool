#include <stddef.h>
#include "dashboard.h"
#include "graphics.h"


static storage_overview_t g_overview;
static storage_category_t g_categories[5];
static hdd_info_t g_hdd_info;
static quick_action_t g_quick_actions[3];

void dashboard_init(void)
{
    g_overview.used_gb      = 312.4f;
    g_overview.free_gb      = 152.6f;
    g_overview.total_gb     = 465.0f;
    g_overview.used_percent = 67;

    g_categories[0] = (storage_category_t){ "Games",    265.7f, 57 };
    g_categories[1] = (storage_category_t){ "Homebrew",  18.4f,  4 };
    g_categories[2] = (storage_category_t){ "Save Data",  9.8f,  2 };
    g_categories[3] = (storage_category_t){ "Packages",  14.7f,  3 };
    g_categories[4] = (storage_category_t){ "Other",      3.8f,  1 };

    g_hdd_info.model       = "CECH-25xx";
    g_hdd_info.firmware    = "4.91";
    g_hdd_info.filesystem  = "exFAT";
    g_hdd_info.temperature_c = 45;

    g_quick_actions[0] = (quick_action_t){ "Scan Storage" };
    g_quick_actions[1] = (quick_action_t){ "Refresh Information" };
    g_quick_actions[2] = (quick_action_t){ "Manage Packages" };
}

static void draw_storage_overview(rect_t area)
{
    draw_panel(area, "STORAGE OVERVIEW");

    draw_text(area.x, area.y + 30, "System Storage", COLOR_TEXT_SECONDARY, 1.0f);

    rect_t bar_area = { area.x, area.y + 50, area.w - 20, 14 };
    float percent = g_overview.used_percent / 100.0f;
    draw_progress_bar(bar_area, percent, COLOR_ACCENT_PURPLE, COLOR_PROGRESS_BG);

    draw_text(area.x, area.y + 75, "Used: 312.4 GB (67%)", COLOR_TEXT_PRIMARY, 1.0f);
    draw_text(area.x + 180, area.y + 75, "Free: 152.6 GB (33%)", COLOR_TEXT_PRIMARY, 1.0f);

    draw_text(area.x, area.y + 100, "Total: 465.0 GB", COLOR_TEXT_PRIMARY, 1.0f);
}

static void draw_category_breakdown(rect_t area)
{
    draw_panel(area, "CATEGORY BREAKDOWN");

    int row_y = area.y + 30;
    int row_height = 22;

    for (int i = 0; i < 5; i++) {
        draw_text(area.x, row_y, g_categories[i].name, COLOR_TEXT_PRIMARY, 1.0f);
        /* TODO: formatar "%.1f GB (%d%%)" dinamicamente via snprintf. */
        draw_text(area.x + 140, row_y, "GB", COLOR_TEXT_PRIMARY, 1.0f);
        draw_text(area.x + 200, row_y, "(%)", COLOR_TEXT_SECONDARY, 1.0f);
        row_y += row_height;
    }
}

static void draw_quick_actions(rect_t area)
{
    draw_panel(area, "QUICK ACTIONS");

    int row_y = area.y + 30;
    int row_height = 30;

    for (int i = 0; i < 3; i++) {
        rect_t row_area = { area.x, row_y, area.w - 20, row_height - 4 };

        if (i == 0) {
           
            draw_highlight_box(row_area, COLOR_ACCENT_PURPLE_DARK);
        }

        draw_text(area.x + 12, row_y + 6, g_quick_actions[i].label,
                   COLOR_TEXT_PRIMARY, 1.0f);
        row_y += row_height;
    }
}

static void draw_hdd_information(rect_t area)
{
    draw_panel(area, "HDD INFORMATION");

    int row_y = area.y + 30;
    int row_height = 24;

    draw_text(area.x, row_y, "Model:", COLOR_TEXT_SECONDARY, 1.0f);
    draw_text(area.x + 100, row_y, g_hdd_info.model, COLOR_TEXT_PRIMARY, 1.0f);
    row_y += row_height;

    draw_text(area.x, row_y, "Firmware:", COLOR_TEXT_SECONDARY, 1.0f);
    draw_text(area.x + 100, row_y, g_hdd_info.firmware, COLOR_TEXT_PRIMARY, 1.0f);
    row_y += row_height;

    draw_text(area.x, row_y, "File System:", COLOR_TEXT_SECONDARY, 1.0f);
    draw_text(area.x + 100, row_y, g_hdd_info.filesystem, COLOR_TEXT_PRIMARY, 1.0f);
    row_y += row_height;

    draw_text(area.x, row_y, "Temperature:", COLOR_TEXT_SECONDARY, 1.0f);
    
    draw_text(area.x + 100, row_y, "45C", COLOR_TEXT_PRIMARY, 1.0f);
}

void dashboard_draw(rect_t content_area)
{
    draw_text(content_area.x, content_area.y, "DASHBOARD", COLOR_ACCENT_PURPLE, 1.4f);
    draw_separator(content_area.x, content_area.y + 30, content_area.w, COLOR_SEPARATOR);

    int panel_top = content_area.y + 50;
    int panel_gap = 20;
    int col_width = (content_area.w - panel_gap) / 2;
    int row_height = 160;

    rect_t overview_area = { content_area.x, panel_top, col_width, row_height };
    rect_t breakdown_area = { content_area.x + col_width + panel_gap, panel_top, col_width, row_height };

    rect_t actions_area = { content_area.x, panel_top + row_height + panel_gap, col_width, row_height };
    rect_t hdd_info_area = { content_area.x + col_width + panel_gap, panel_top + row_height + panel_gap, col_width, row_height };

    draw_storage_overview(overview_area);
    draw_category_breakdown(breakdown_area);
    draw_quick_actions(actions_area);
    draw_hdd_information(hdd_info_area);
}
