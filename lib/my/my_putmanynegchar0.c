/*
** EPITECH PROJECT, 2023
** my_float.c
** File description:
** Displaying a float without printf
*/
#include <unistd.h>
#include "my.h"

int my_putmanynegchar0(int i, int i2, double *f2, int science)
{
    int count;

    if (*f2 < 0.1) {
        my_putchar('-');
        my_put_nbr(i);
        my_putchar('.');
        for (count = 0; count < science; count++) {
            my_put_nbr(0);
        }
        my_put_nbr(i2);
    } else {
        my_putchar('-');
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(i2);
    }
    return 0;
}
