/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** bucket.c
*/

#include "my.h"

static bool clicked_bucket(mgst *m, all_buts *but, sfRectangleShape *rect)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect border = sfRectangleShape_getGlobalBounds(rect);

    if ((sfFloatRect_contains(&border, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && m->is_bucket == false) {
        return true;
    }
    return false;
}

void bucket(mgst *m, all_buts *buts)
{
    sfVector2i mouse_pose = sfMouse_getPositionRenderWindow(m->window);

    if (is_button_clicked(buts->bucket, m) == sfTrue) {
        m->is_bucket = clicked_bucket(m, buts, buts->bucket->rect);
    } else if (is_hooved(buts->bucket, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->bucket->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->bucket->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->bucket->rect, 0);
        sfRectangleShape_setFillColor(buts->bucket->rect, sfTransparent);
    }
    return;
}
