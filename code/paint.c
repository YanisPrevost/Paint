/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** paint.c
*/

#include "my.h"

static sfBool my_paint_test(mgst *m, sfBool is_pressed)
{
    if (m->event.type == sfEvtClosed || (m->event.type ==
    sfEvtKeyPressed && m->event.key.code == sfKeyEscape))
        sfRenderWindow_close(m->window);
    sfRenderWindow_clear(m->window, GREY);
    return sfMouse_isButtonPressed(sfMouseLeft);
}

void my_paint(mgst *m, sfSprite *draw_sheet, sfBool is_pressed, all_buts *buts)
{
    static sfVector2i pos_mouse_prec = {0, 0};
    static sfVector2i pos_mouse_first = {0, 0};
    sfVector2i pos_mouse;

    is_pressed = my_paint_test(m, is_pressed);
    if (is_pressed == sfTrue) {
        pos_mouse = sfMouse_getPositionRenderWindow(m->window);
        pos_mouse.x -= 360;
        pos_mouse.y -= 140;
        if (pos_mouse_first.x == 0 && pos_mouse_first.y == 0) {
            pos_mouse_first = pos_mouse;
        } else
            dessin(m, pos_mouse, pos_mouse_prec, m->current_color);
        pos_mouse_prec = pos_mouse;
    } else
        pos_mouse_first = (sfVector2i){0, 0};
    print_buttons(m, buts);
    print_img(m);
    is_in_circle(m, buts);
}
