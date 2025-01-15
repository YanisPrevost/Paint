/*
** EPITECH PROJECT, 2023
** my_float.c
** File description:
** Displaying a float without printf
*/
#include <unistd.h>
#include "my.h"

int my_monkey(int i, int i2, double *f2, int science)
{
    int count;

    if (*f2 < 0.1) {
        my_put_nbr(i);
        my_putchar('.');
        for (count = 0; count < science; count++) {
            my_put_nbr(0);
        }
        my_put_nbr(i2);
    } else {
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(i2);
    }
    return 0;
}

int my_float(double f)
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
        my_monkey(i, i2, &f2, science);
    }
}
