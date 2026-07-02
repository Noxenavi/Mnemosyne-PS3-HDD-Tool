#ifndef UI_H
#define UI_H

#include "menu.h"


typedef struct {
    menu_state_t menu;
    int running; 
} ui_state_t;

void ui_init(ui_state_t *ui);
void ui_update(ui_state_t *ui);
void ui_draw(ui_state_t *ui);
void ui_shutdown(ui_state_t *ui);

#endif 