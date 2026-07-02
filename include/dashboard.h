#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "graphics.h"

typedef struct {
    const char *name;
    float size_gb;
    int percent;
} storage_category_t;

typedef struct {
    float used_gb;
    float free_gb;
    float total_gb;
    int used_percent;
} storage_overview_t;

typedef struct {
    const char *model;
    const char *firmware;
    const char *filesystem;
    int temperature_c;
} hdd_info_t;

typedef struct {
    const char *label;
} quick_action_t;

void dashboard_init(void);
void dashboard_draw(rect_t content_area);

#endif