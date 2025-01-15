/*
** EPITECH PROJECT, 2023
** My_paint
** File description:
** pipette.c
*/

#include "my.h"

void create_pipette(mgst *m, all_buts *buts)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f koko = {0.4, 0.4};
    sfVector2f pose = {1690, 300};

    m->pipe_text = sfTexture_createFromFile("code/asset/pipette.png", NULL);
    sfSprite_setTexture(sprite, m->pipe_text, sfTrue);
    sfSprite_setScale(sprite, koko);
    sfSprite_setPosition(sprite, pose);
    m->Pip = sprite;
    return;
}

void create_bucket(mgst *m, all_buts *buts)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f koko = {0.3, 0.3};
    sfVector2f pose = {1768, 300};

    m->T_bucket = sfTexture_createFromFile("code/asset/bc.png", NULL);
    sfSprite_setTexture(sprite, m->T_bucket, sfTrue);
    sfSprite_setScale(sprite, koko);
    sfSprite_setPosition(sprite, pose);
    m->Buck = sprite;
    return;
}

sfSprite *create_circle(mgst *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {50, 490};

    m->cici = sfImage_createFromFile("code/asset/noir.png");
    m->T_circle = sfTexture_createFromImage(m->cici, NULL);
    sfSprite_setTexture(sprite, m->T_circle, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

static bool clicked_pipette(mgst *m, all_buts *but, sfRectangleShape *rect)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(rect);

    if ((sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && m->is_pipette == false) {
        return true;
    }
    return false;
}

void is_in_circle(mgst *m, all_buts *but)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfSprite_getGlobalBounds(m->circle);
    sfVector2f pos_img = sfSprite_getPosition(m->circle);

    pos_mouse.y - 29;
    if ((sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed)
    && (m->event.key.code == sfMouseLeft)
    && m->is_pipette == true) {
        m->current_color = sfImage_getPixel(m->cici, pos_mouse.x - 50,
        pos_mouse.y - 490);
    }
}

void pipette(mgst *m, all_buts *buts)
{
    sfVector2i mouse_pose = sfMouse_getPositionRenderWindow(m->window);

    if (is_button_clicked(buts->pipette, m) == sfTrue) {
        m->is_pipette = clicked_pipette(m, buts, buts->pipette->rect);
    } else if (is_hooved(buts->pipette, m) == sfTrue) {
        sfRectangleShape_setOutlineColor(buts->pipette->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(buts->pipette->rect, 5);
    } else {
        sfRectangleShape_setOutlineThickness(buts->pipette->rect, 0);
        sfRectangleShape_setFillColor(buts->pipette->rect, sfTransparent);
    }
    return;
}
