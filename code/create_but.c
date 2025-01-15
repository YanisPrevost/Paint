/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"

static bool extension(char *filename)
{
    int i = 0;
    int j;

    while (filename[i] != '.') {
        i++;
    }
    if (my_strcmp(&filename[i], ".jpg") == -1 &&
    my_strcmp(&filename[i], ".png") == -1 &&
    my_strcmp(&filename[i], ".bmp") == -1 &&
    my_strcmp(&filename[i], ".jpeg") == -1) {
        return false;
    }
    return true;
}

void open_button(mgst *m, all_buts *buts)
{
    sfImage *new_img;
    char *filename = malloc(sizeof(char *));
    size_t size_file = 10;
    sfIntRect resize = {0, 0, 1200, 800};

    if (is_button_clicked(buts->file_save, m) == sfTrue) {
        my_printf("\033[1;31mNom du fichier à ouvrir ?\n> \033[0m");
        getline(&filename, &size_file, stdin);
        filename[my_strlen(filename) - 1] = '\0';
        if (open(filename, O_RDONLY) == -1 || extension(filename) == false) {
            my_printf("Please enter a valid file.\n");
            return;
        }
        new_img = sfImage_createFromFile(filename);
        sfImage_copyImage(m->draw_sfrc, new_img, 0, 0, resize, sfTrue);
        sfImage_destroy(new_img);
    } else if (is_hooved(buts->file_save, m) == sfTrue)
        sfRectangleShape_setFillColor(buts->file_save->rect, GREY);
    else
        sfRectangleShape_setFillColor(buts->file_save->rect, sfWhite);
}

void save_button(mgst *m, all_buts *buts)
{
    char *filename = malloc(sizeof(char *));
    size_t size = 10;

    if (is_button_clicked(buts->file_save_as, m) == sfTrue) {
        my_printf("\033[1;31mNom du fichier à sauvegarder ?\n> \033[0m");
        getline(&filename, &size, stdin);
        filename[my_strlen(filename) - 1] = '\0';
        sfImage_saveToFile(m->draw_sfrc, filename);
    } else if (is_hooved(buts->file_save_as, m) == sfTrue)
        sfRectangleShape_setFillColor(buts->file_save_as->rect, GREY);
    else
        sfRectangleShape_setFillColor(buts->file_save_as->rect, sfWhite);
    free(filename);
}

void reset_tests(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->file_new, m) == sfTrue) {
        sfImage_destroy(m->draw_sfrc);
        m->current_color = sfBlack;
        m->draw_sfrc = sfImage_createFromColor(1200, 800, sfWhite);
    } else if (is_hooved(buts->file_new, m) == sfTrue)
        sfRectangleShape_setFillColor(buts->file_new->rect, GREY);
    else
        sfRectangleShape_setFillColor(buts->file_new->rect, sfRed);
}

void plus_test(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->edit_s_p, m) == sfTrue) {
        if (m->current_size < 80)
            m->current_size += 3;
    } else if (is_hooved(buts->edit_s_p, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->edit_s_p->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->edit_s_p->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->edit_s_p->rect, 0);
        sfRectangleShape_setFillColor(buts->edit_s_p->rect, sfBlack);
    }
}

void minus_test(mgst *m, all_buts *buts)
{
    if (is_button_clicked(buts->edit_s_m, m) == sfTrue) {
        if (m->current_size > 0)
            m->current_size -= 3;
    } else if (is_hooved(buts->edit_s_m, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->edit_s_m->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->edit_s_m->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->edit_s_m->rect, 0);
        sfRectangleShape_setFillColor(buts->edit_s_m->rect, sfBlack);
    }
}
