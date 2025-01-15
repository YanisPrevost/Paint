/*
** EPITECH PROJECT, 2023
** edjg
** File description:
** sdfgdsdfgs
*/
#include <unistd.h>
#include "my.h"
#include <stdarg.h>

int my_spacechoicesuppsuite(int i, int i2, float f2, int science)
{
    int temp = i;

    my_spaceputmanychar(i, i2, &f2);
        if (science < 10) {
            my_putstr("E+0");
        } else {
            my_putstr("E+");
        }
        my_put_nbr(science);
}

int my_spacechoicesupp(int i, int i2, float f2, int science)
{
    int temp = i;

    if (temp < 0) {
        my_putmanynegchar(i, i2, &f2);
        if (science < 10) {
            my_putstr("E+0");
        } else {
            my_putstr("E+");
        }
        my_put_nbr(science);
        return 0;
    } else {
        my_spacechoicesuppsuite(i, i2, f2, science);
        return 0;
    }
    my_otherchoicesupp(i, i2, f2, science);
}

int my_spaceexsupp(float *f, int *science2, int *i)
{
    while (*f > 10 ^ *f < -10) {
        *f = *f / 10.0;
        *science2 = *science2 + 1;
    }
    *i = (int)*f;
}

int my_spaceexpotentielsupp(float f, int nbr, int science)
{
    int n = 6;
    int science2 = 0;
    int i;
    float f2;
    int i2;

    my_spaceexsupp(&f, &science2, &i);
    if (i == 0) {
        count0(&f, &science);
        my_spaceexpotentielsupp(f, 1, science);
        return 0;
    } else {
        f2 = (f - i);
        i2 = f2 * my_compute_speit(10, n);
    }
    if (nbr == 1) {
        my_otherchoicesupp(i, i2, f2, science);
        return 0;
    }
    my_spacechoicesupp(i, i2, f2, science2);
}
