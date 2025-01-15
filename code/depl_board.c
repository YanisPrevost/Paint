/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** depl_board.c
*/

#include "my.h"

static bool clicked(mgst *m, sfRectangleShape *rect, bool button)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect border = sfRectangleShape_getGlobalBounds(rect);

    if ((sfFloatRect_contains(&border, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && button == false) {
        return true;
    }
    return false;
}

bool clicked_gomme(mgst *m, sfRectangleShape *rect)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect border = sfRectangleShape_getGlobalBounds(rect);

    if ((sfFloatRect_contains(&border, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && m->eraser == false) {
        return true;
    }
    m->current_color = sfBlack;
    return false;
}

void option(mgst *m, sfRectangleShape *rect, button_struct *boutton, char *str)
{
    if (is_hooved(boutton, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(rect, sfBlack);
        sfRectangleShape_setOutlineThickness(rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(rect, 0);
        sfRectangleShape_setFillColor(rect, sfWhite);
    }
    dropdown_file(m, str);
    sfRenderWindow_drawRectangleShape(m->window, rect, NULL);
    sfRenderWindow_drawText(m->window, m->text2, NULL);
}

void file_depl(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->file, m) == sfTrue) {
        m->file_but = clicked(m, buts->file->rect, m->file_but);
    } else if (is_hooved(buts->file, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->file->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->file->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->file->rect, 0);
        sfRectangleShape_setFillColor(buts->file->rect, sfWhite);
    }
    if (m->file_but == true) {
        option(m, buts->file_new->rect, buts->file_new, "  new_file");
        option(m, buts->file_save->rect, buts->file_save, "\topen");
        option(m, buts->file_save_as->rect, buts->file_save_as, "\tsave");
    }
    return;
}

void edit_depl(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->edit, m) == sfTrue) {
        m->edit_but = clicked(m, buts->edit->rect, m->edit_but);
    } else if (is_hooved(buts->edit, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->edit->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->edit->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->edit->rect, 0);
        sfRectangleShape_setFillColor(buts->edit->rect, sfWhite);
    }
    if (m->edit_but == true) {
        option(m, buts->edit_s_p->rect, buts->edit_s_p, "+  or");
        option(m, buts->edit_s_m->rect, buts->edit_s_m, "-");
        option(m, buts->edit_gomme->rect, buts->edit_gomme, "eraser");
        option(m, buts->edit_brush->rect, buts->edit_brush, "brush");
    }
    return;
}

void help_depl(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->help, m) == sfTrue) {
        m->help_but = clicked(m, buts->help->rect, m->help_but);
    } else if (is_hooved(buts->help, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->help->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->help->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->help->rect, 0);
        sfRectangleShape_setFillColor(buts->help->rect, sfWhite);
    }
    if (m->help_but == true) {
        option(m, buts->more->rect, buts->more, "tuto");
        option(m, buts->about->rect, buts->about, "about");
    }
    return;
}
