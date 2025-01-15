/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

button_struct *init_button(sfVector2f position, sfVector2f size, sfColor color)
{
    button_struct *button = malloc(sizeof(button_struct));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, color);
    return button;
}

sfBool is_button_clicked(button_struct *button, mgst *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if ((sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed) &&
    (m->event.key.code == sfMouseLeft)) {
        sfRectangleShape_setFillColor(button->rect, sfBlue);
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_hooved(button_struct *button, mgst *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue) {
        return sfTrue;
    }
    return sfFalse;
}

void print_size(mgst *m)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f size;
    sfVector2f pos;

    size.x = m->current_size;
    size.y = m->current_size;
    pos.x = 215;
    pos.y = 333;
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, m->current_color);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRenderWindow_drawRectangleShape(m->window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}
