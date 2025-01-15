/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

sfView *create_view(mgst *m)
{
    sfView *view = sfView_create();
    sfVector2f center;

    center.x = 360;
    center.y = 140;
    sfView_setSize(view, (sfVector2f){800, 600});
    sfView_setCenter(view, center);
    return view;
}

sfSprite *create_draw_srfc(mgst *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos;

    pos.x = 360;
    pos.y = 140;
    m->draw_sfrc = sfImage_createFromColor(1200, 800, sfWhite);
    m->sfrc_texture = sfTexture_createFromImage(m->draw_sfrc, NULL);
    sfSprite_setTexture(sprite, m->sfrc_texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

static void next_next(sfVector2f size, all_buts *buts, sfVector2f pos)
{
    buts->edit_gomme = init_button(pos, size, sfTransparent);
    pos.y += 50;
    buts->edit_brush = init_button(pos, size, sfTransparent);
    pos.y += 50;
    buts->edit_sqr = init_button(pos, size, sfTransparent);
    pos.x = 255;
    pos.y = 50;
    buts->more = init_button(pos, size, sfTransparent);
    pos.y += 50;
    buts->about = init_button(pos, size, sfTransparent);
    pos.y = 300;
    pos.x = 1690;
    size.x = 59;
    size.y = 59;
    buts->pipette = init_button(pos, size, sfTransparent);
    pos.y = 300;
    pos.x = 1768;
    size.x = 65;
    size.y = 65;
    buts->bucket = init_button(pos, size, sfTransparent);
}

static void next_init(mgst *m, sfVector2f size, all_buts *buts, sfVector2f pos)
{
    pos.x = 5;
    pos.y = 50;
    buts->file_new = init_button(pos, size, sfRed);
    pos.y += 50;
    buts->file_save = init_button(pos, size, sfRed);
    pos.y += 50;
    buts->file_save_as = init_button(pos, size, sfRed);
    pos.x = 135;
    pos.y = 50;
    size.x = 30;
    size.y = 30;
    buts->edit_s_p = init_button(pos, size, sfTransparent);
    pos.x += 57;
    buts->edit_s_m = init_button(pos, size, sfTransparent);
    pos.y = 100;
    pos.x = 130;
    size.x = 100;
    size.y = 30;
    next_next(size, buts, pos);
}

void init_all_buttons(mgst *m, all_buts *buts)
{
    sfVector2f pos = {50, 50};
    sfVector2f size = {100, 100};

    size.x = 50;
    size.y = 50;
    pos.x = 1920 / 2;
    pos.y = 950;
    buts->size_minus = init_button(pos, size, sfBlack);
    pos.x += 75;
    buts->size_plus = init_button(pos, size, sfBlack);
    pos.x = 5;
    pos.y = 5;
    size.x = 100;
    size.y = 30;
    buts->file = init_button(pos, size, sfTransparent);
    pos.x += 125;
    buts->edit = init_button(pos, size, sfTransparent);
    pos.x += 125;
    buts->help = init_button(pos, size, sfTransparent);
    next_init(m, size, buts, pos);
}

static void more_init(mgst *m)
{
    m->is_pipette = false;
    m->is_bucket = false;
    m->current_color = DEFAULT_COLOR;
    m->video_mode.width = DEFAULT_WIDTH;
    m->video_mode.height = DEFAULT_HEIGHT;
    m->video_mode.bitsPerPixel = DEFAULT_BPP;
    return;
}

static void init_booleans(mgst *m)
{
    m->eraser = sfFalse;
    m->file_but = false;
    m->edit_but = false;
    m->is_circle = true;
    m->is_square = false;
    m->help_but = false;
    m->is_brush = false;
}

void init_function(mgst *m, all_buts *buts)
{
    m->current_size = DEFAULT_SIZE;
    init_booleans(m);
    more_init(m);
    set_texte(m);
    set_menu(m, buts);
    m->window = sfRenderWindow_create(m->video_mode,
    "My_Paint", sfResize | sfClose, NULL);
    create_pipette(m, buts);
    create_bucket(m, buts);
    init_all_buttons(m, buts);
    init_palette(buts);
    m->draw_sheet = create_draw_srfc(m);
    sfRenderWindow_setFramerateLimit(m->window, 120);
    icone(m);
    m->circle = create_circle(m);
}
