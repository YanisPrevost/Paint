/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** more_test.c
*/

#include "my.h"

void more_test(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->more, m) == sfTrue) {
        print_a_file("help_message.txt");
    } else if (is_hooved(buts->more, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->more->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->more->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->more->rect, 0);
        sfRectangleShape_setFillColor(buts->more->rect, sfWhite);
    }
}

void about_test(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->about, m) == sfTrue) {
        print_a_file("about_message.txt");
    } else if (is_hooved(buts->about, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->about->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->about->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->about->rect, 0);
        sfRectangleShape_setFillColor(buts->about->rect, sfWhite);
    }
}

void sqr_test(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->edit_sqr, m) == sfTrue) {
        m->is_square == true;
    } else if (is_hooved(buts->edit_sqr, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->edit_sqr->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->edit_sqr->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->edit_sqr->rect, 0);
        sfRectangleShape_setFillColor(buts->edit_sqr->rect, sfWhite);
    }
}

bool clicked6(mgst *m, sfRectangleShape *rect)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect border = sfRectangleShape_getGlobalBounds(rect);

    if ((sfFloatRect_contains(&border, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && m->is_brush == false) {
        return true;
    }
    m->current_color = sfBlack;
    return false;
}

void brush_test(mgst *m, all_buts *buts)
{
    sfColor tmp = m->current_color;

    if (is_button_clicked(buts->edit_brush, m) == sfTrue) {
        m->is_brush = clicked6(m, buts->edit_brush->rect);
    } else if (is_hooved(buts->edit_brush, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->edit_brush->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->edit_brush->rect, 5);
    } else {
        sfRectangleShape_setFillColor(buts->edit_brush->rect, sfWhite);
    }
}
