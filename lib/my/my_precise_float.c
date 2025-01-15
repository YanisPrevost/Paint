/*
** EPITECH PROJECT, 2023
** my_precise_float.c
** File description:
** Displaying a float without printf
*/
#include "my.h"

int my_precise_float(float f, int n)
{
    char b;
    int i = (int)f;
    float f2 = (f - i);
    int i2 = (int)(f2 * my_compute_speit(10, n));

    if (i2 < 1 & i < 1) {
        b = my_putstr("inf");
        return 0;
    }
    if (f2 < 0.1) {
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(0);
        my_put_nbr(i2);
        } else {
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(i2);
    }
}
