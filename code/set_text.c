/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** set_text.c
*/

#include "my.h"

void set_menu(mgst *m, all_buts *buts)
{
    m->text2 = sfText_create();
    m->font2 = sfFont_createFromFile("code/asset/police.ttf");
    sfText_setFont(m->text2, m->font2);
    sfText_setCharacterSize(m->text2, 20);
    sfText_setFillColor(m->text2, sfBlack);
}

void set_texte(mgst *m)
{
    sfVector2f textPos = {10, 8};

    m->text = sfText_create();
    m->font = sfFont_createFromFile("code/asset/police.ttf");
    sfText_setFont(m->text, m->font);
    sfText_setString(m->text, "\t file\t\t   \tedit\t\t   \
    help\n\n\n\n\n\n\n\t\t\t\t\n\n\n\n\n\n\n        Preview Brush:");
    sfText_setCharacterSize(m->text, 20);
    sfText_setFillColor(m->text, sfBlack);
    sfText_setPosition(m->text, textPos);
}
