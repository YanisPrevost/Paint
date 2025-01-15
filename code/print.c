/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

static void brush(int rayon, sfVector2i pos_ms, mgst *m)
{
    int y = 0;
    int x = rayon;
    int crit = 1 - rayon;

    for (; x >= y; y++) {
        for (int xi = -x; xi <= x; xi++) {
            sfImage_setPixel(m->draw_sfrc, xi + pos_ms.x, y
            + pos_ms.y, m->current_color);
            sfImage_setPixel(m->draw_sfrc, xi + pos_ms.x, -y +
            pos_ms.y, m->current_color);
        }
        if (crit <= 0) {
            crit += 2 * y + 1;
        } else {
            x--;
            crit += 2 * (y - x) + 1;
        }
    }
}

static void eraser(int rayon, sfVector2i pos_ms, mgst *m)
{
    int y = 0;
    int x = rayon;
    int crit = 1 - rayon;

    for (; x >= y; y++) {
        for (int xi = -x; xi <= x; xi++) {
            sfImage_setPixel(m->draw_sfrc, xi +
            pos_ms.x, y + pos_ms.y, sfWhite);
            sfImage_setPixel(m->draw_sfrc, xi +
            pos_ms.x, -y + pos_ms.y, sfWhite);
        }
        if (crit <= 0) {
            crit += 2 * y + 1;
        } else {
            x--;
            crit += 2 * (y - x) + 1;
        }
    }
}

static bool is_in_surface(int x0, int y0)
{
    if (x0 < 1200 && y0 < 800 && x0 > 0 && y0 > 0) {
        return true;
    }
    return false;
}

static void pencil(sfVector2i prev, sfVector2i pos_ms, mgst *m)
{
    int dx = abs(pos_ms.x - prev.x);
    int dy = abs(pos_ms.y - prev.y);
    int sx = prev.x < pos_ms.x ? 1 : -1;
    int sy = prev.y < pos_ms.y ? 1 : -1;
    int err = dx - dy;
    int e2;

    while ((prev.x != pos_ms.x || prev.y != pos_ms.y) &&
    is_in_surface(prev.x, prev.y) == true) {
        sfImage_setPixel(m->draw_sfrc, prev.x, prev.y, m->current_color);
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            prev.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            prev.y += sy;
        }
    }
}

static int option_dessin(mgst *m, int rayon, sfVector2i pos_mouse)
{
    if (m->is_pipette == true) {
        m->current_color = sfImage_getPixel(m->draw_sfrc,
        pos_mouse.x, pos_mouse.y);
        return 0;
    }
    if (m->is_bucket == true) {
        sfImage_destroy(m->draw_sfrc);
        m->draw_sfrc = sfImage_createFromColor(1200, 800, m->current_color);
        return 0;
    }
    if (m->eraser == true) {
        eraser(rayon, pos_mouse, m);
        return 0;
    }
    if (m->is_brush == true) {
        brush(rayon, pos_mouse, m);
        return 0;
    }
    return 1;
}

void dessin(mgst *m, sfVector2i pos_ms, sfVector2i pos_ms_prec, sfColor color)
{
    sfColor tmp = m->current_color;
    int rayon = m->current_size / 2;

    if (pos_ms.x > rayon && pos_ms.x < 1200 - rayon
    && pos_ms.y > rayon && pos_ms.y < 800 - rayon) {
        if (option_dessin(m, rayon, pos_ms) == 0) {
        } else
            pencil(pos_ms_prec, pos_ms, m);
    }
}

void print_img(mgst *m)
{
    m->sfrc_texture = sfTexture_createFromImage(m->draw_sfrc, NULL);
    sfSprite_setTexture(m->draw_sheet, m->sfrc_texture, sfFalse);
    sfRenderWindow_drawSprite(m->window, m->draw_sheet, NULL);
    cursor_tests(m);
    sfRenderWindow_display(m->window);
    sfTexture_destroy(m->sfrc_texture);
}

static void other_print(mgst *m, all_buts *buts)
{
    print_size(m);
    color_test(buts, m);
    disp_palette(buts, m);
    file_depl(m, buts);
    edit_depl(m, buts);
    help_depl(m, buts);
    pipette(m, buts);
    bucket(m, buts);
}

void print_buttons(mgst *m, all_buts *buts)
{
    if (m->file_but == true) {
        save_button(m, buts);
        open_button(m, buts);
        reset_tests(m, buts);
    }
    if (m->edit_but == true) {
        sqr_test(m, buts);
        brush_test(m, buts);
        minus_test(m, buts);
        plus_test(m, buts);
    }
    if (m->help_but == true) {
        more_test(m, buts);
        about_test(m, buts);
    }
    other_print(m, buts);
    sfRenderWindow_drawText(m->window, m->text, NULL);
}
