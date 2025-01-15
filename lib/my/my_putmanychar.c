/*
** EPITECH PROJECT, 2023
** ijiuh
** File description:
** hjioh
*/
#include "my.h"

int my_putmanychar(int i, int i2, float *f2)
{
    if (*f2 < 0.1) {
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(0);
        my_put_nbr(my_arrondie(i2));
    } else {
        my_put_nbr(i);
        my_putchar('.');
        my_put_nbr(my_arrondie(i2));
    }
    return 0;
}
