/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

void print_a_file(char *filename)
{
    int fd;
    char buffer[BUFFSIZE];
    int size;
    int i = 1;

    fd = open(filename, O_RDONLY);
    size = read(fd, buffer, BUFFSIZE);
    buffer[BUFFSIZE] = '\0';
    write(1, buffer, size);
    write(1, "\n", 1);
    close(fd);
    i++;
}

static int help(int ac, char **av)
{
    if (my_strcmp(av[1], "-h") == 55) {
        my_printf("# USAGE : ./my_paint\n");
        return 0;
    } else {
        my_printf("The program take only one parameter !\n");
        return 84;
    }
}

void icone(mgst *m)
{
    sfImage *icone = sfImage_createFromFile("code/asset/icone.jpg");
    const sfUint8 *tab = sfImage_getPixelsPtr(icone);

    sfRenderWindow_setIcon(m->window, 400, 400, tab);
}

void destroy_fct(mgst *m)
{
    sfSprite_destroy(m->Pip);
    sfSprite_destroy(m->circle);
    sfRenderWindow_destroy(m->window);
    sfTexture_destroy(m->T_bucket);
    sfSprite_destroy(m->Buck);
    sfImage_destroy(m->cici);
    sfImage_destroy(m->draw_sfrc);
    sfText_destroy(m->text);
    sfText_destroy(m->text2);
    sfTexture_destroy(m->pipe_text);
}

int main(int ac, char **av)
{
    mgst m;
    all_buts *buts;
    sfSprite *draw_sheet;
    sfBool is_pressed;

    if (ac == 2)
        return help(ac, av);
    else if (ac >= 3)
        return 84;
    init_function(&m, buts);
    is_pressed = sfFalse;
    while (sfRenderWindow_isOpen(m.window)) {
        while (sfRenderWindow_pollEvent(m.window, &m.event)) {
            my_paint(&m, draw_sheet, is_pressed, buts);
        }
    }
    destroy_fct(&m);
    return 0;
}
