/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"

void pipette_cursor(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./code/asset/pipette.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.27, 0.27};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x;
    pos_sprite.y = (float)pos_mouse.y - 29;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void bucket_cursor(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("./code/asset/bc.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.2, 0.2};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x;
    pos_sprite.y = (float)pos_mouse.y - 29;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void eraser_cursor(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./code/asset/eraser.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.1, 0.1};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x - 20;
    pos_sprite.y = (float)pos_mouse.y - 35;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

static void pen_cursor(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./code/asset/pen.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x - 25;
    pos_sprite.y = (float)pos_mouse.y - 105;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void brush_cursor(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./code/asset/pinceau.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x - 35;
    pos_sprite.y = (float)pos_mouse.y - 30;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

static void more_cursor(mgst *m, sfVector2i pos_ms)
{
    if (m->is_bucket == true) {
        bucket_cursor(m->window);
        m->is_pipette = false;
        m->eraser = false;
        m->is_brush = false;
        return;
    }
    if (m->is_brush == true) {
        brush_cursor(m->window);
        m->is_pipette = false;
        m->eraser = false;
        m->is_bucket = false;
        return;
    }
    if (pos_ms.x > 359 && pos_ms.y > 142 &&
    pos_ms.x < 1560 && pos_ms.y < 940) {
        pen_cursor(m->window);
    } else
        sfRenderWindow_setMouseCursorVisible(m->window, sfTrue);
}

void cursor_tests(mgst *m)
{
    sfVector2i pos_ms = sfMouse_getPositionRenderWindow(m->window);

    if (m->is_pipette == true) {
        pipette_cursor(m->window);
        m->eraser = false;
        m->is_bucket = false;
        m->is_brush = false;
        return;
    }
    if (m->eraser == true) {
        eraser_cursor(m->window);
        m->is_pipette = false;
        m->is_bucket = false;
        m->is_brush = false;
        return;
    }
    more_cursor(m, pos_ms);
}
