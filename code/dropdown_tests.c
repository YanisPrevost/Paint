/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** depl_board.c
*/

#include "my.h"

void help_dropdown(mgst *m, sfVector2f current, char *str)
{
    if (my_strcmp(str, "tuto") == 0) {
        current.x = 280;
        current.y = 50;
    }
    if (my_strcmp(str, "about") == 0) {
        current.x = 280;
        current.y = 100;
    }
    sfText_setPosition(m->text2, current);
    sfText_setString(m->text2, str);
    return;
}

void edit_test(mgst *m, sfVector2f current, char *str)
{
    if (my_strcmp(str, "+  or") == 0) {
        current.x = 143;
        current.y = 52;
    }
    if (my_strcmp(str, "-") == 0) {
        current.x = 202;
        current.y = 52;
    }
    if (my_strcmp(str, "eraser") == 0) {
        current.x = 150;
        current.y = 100;
    }
    if (my_strcmp(str, "brush") == 0) {
        current.x = 150;
        current.y = 150;
    }
    help_dropdown(m, current, str);
    return;
}

void dropdown_file(mgst *m, char *str)
{
    sfVector2f current;

    if (my_strcmp(str, "  new_file") == 0) {
        current.x = 5;
        current.y = 50;
    }
    if (my_strcmp(str, "\topen") == 0) {
        current.x = 5;
        current.y = 100;
    }
    if (my_strcmp(str, "\tsave") == 0) {
        current.x = 5;
        current.y = 150;
    }
    edit_test(m, current, str);
}
