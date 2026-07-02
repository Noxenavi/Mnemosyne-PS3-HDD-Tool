#include "ui.h"

int main(void)
{
    ui_state_t ui;

    ui_init(&ui);

    while (ui.running) {
        ui_update(&ui);
        ui_draw(&ui);
    }

    ui_shutdown(&ui);

    return 0;
}
