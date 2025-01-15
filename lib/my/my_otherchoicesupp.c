/*
** EPITECH PROJECT, 2023
** poijoi
** File description:
** jlnkhbjk
*/

#include "my.h"

int my_otherchoicesupp(int i, int i2, float f2, int science)
{
    int temp = i;

    if ((temp == 0) ^ (temp > 0) ^ (temp < 0)) {
        my_putmanychar(i, i2, &f2);
        my_putstr("E-");
        if (science >= 0 && science < 10) {
            my_put_nbr(0);
            my_put_nbr(science);
            return 0;
        } else {
            my_put_nbr(science);
            return 0;
        }
    }
    return 0;
}
