/*
** EPITECH PROJECT, 2023
** vhhigu
** File description:
** jchvbjhgufy
*/

#include "my.h"

int my_otherchoice(int i, int i2, float f2, int science)
{
    int temp = i;

    if ((temp == 0) ^ (temp > 0) ^ (temp < 0)) {
        my_putmanychar(i, i2, &f2);
        my_putstr("e-");
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
