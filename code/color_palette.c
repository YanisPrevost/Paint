/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

void init_palette(all_buts *but)
{
    sfVector2f pos = {1700, 400};
    sfVector2f size = {50, 50};

    but->black = init_button(pos, size, sfBlack);
    pos.y += 75;
    but->white = init_button(pos, size, sfWhite);
    pos.y += 75;
    but->green = init_button(pos, size, sfGreen);
    pos.y += 75;
    but->yellow = init_button(pos, size, sfYellow);
    pos.y = 400;
    pos.x += 75;
    but->red = init_button(pos, size, sfRed);
    pos.y += 75;
    but->cyan = init_button(pos, size, sfCyan);
    pos.y += 75;
    but->magenta = init_button(pos, size, sfMagenta);
    pos.y += 75;
    but->blue = init_button(pos, size, sfBlue);
}

void disp_palette(all_buts *but, mgst *m)
{
    sfRenderWindow_drawRectangleShape(m->window, but->black->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->white->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->green->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->yellow->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->red->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->cyan->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->magenta->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->blue->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->file->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->edit->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->help->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->pipette->rect, NULL);
    sfRenderWindow_drawSprite(m->window, m->Pip, NULL);
    sfRenderWindow_drawRectangleShape(m->window, but->bucket->rect, NULL);
    sfRenderWindow_drawSprite(m->window, m->Buck, NULL);
    sfRenderWindow_drawSprite(m->window, m->circle, NULL);
}

void colors(mgst *m, button_struct *button, sfColor color)
{
    if (is_button_clicked(button, m) == sfTrue) {
        m->current_color = color;
    } else if (is_hooved(button, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(button->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(button->rect, 5);
    } else {
        sfRectangleShape_setFillColor(button->rect, color);
        sfRectangleShape_setOutlineThickness(button->rect, 0);
    }
}

static void eraser(mgst *m, button_struct *button, sfColor color)
{
    if (is_button_clicked(button, m) == sfTrue) {
        m->current_color = color;
        m->eraser = clicked_gomme(m, button->rect);
    } else if (is_hooved(button, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(button->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(button->rect, 5);
    } else {
        sfRectangleShape_setFillColor(button->rect, color);
        sfRectangleShape_setOutlineThickness(button->rect, 0);
    }
}

void color_test(all_buts *but, mgst *m)
{
    colors(m, but->black, sfBlack);
    colors(m, but->green, sfGreen);
    colors(m, but->yellow, sfYellow);
    colors(m, but->red, sfRed);
    colors(m, but->cyan, sfCyan);
    colors(m, but->magenta, sfMagenta);
    colors(m, but->blue, sfBlue);
    colors(m, but->white, CACA);
    if (m->edit_but == true)
        eraser(m, but->edit_gomme, sfWhite);
}
