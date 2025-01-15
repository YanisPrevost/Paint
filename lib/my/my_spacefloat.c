/*
** EPITECH PROJECT, 2023
** my_float.c
** File description:
** Displaying a float without printf
*/
#include <unistd.h>
#include "my.h"

int my_spacefloat(double f)
{
    int n = 6;
    int i = (int)f;
    int temp = i;
    double f2 = (f - i);
    int i2;
    int science = 0;

    if (f2 > 0.0 ^ f2 < -0.0) {
    counter(f2, &science);
    }
    i2 = (int)(f2 * my_compute_speit(10, n));
    if (temp < 0) {
        my_putmanynegchar0(i, i2, &f2, science);
    } else {
        my_putmanychar0(i, i2, &f2, science);
    }
}
