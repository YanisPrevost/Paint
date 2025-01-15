/*
** EPITECH PROJECT, 2023
** my_float.c
** File description:
** Displaying a float without printf
*/
#include <unistd.h>
#include "my.h"

int counter(double f, int *science)
{
    if (f < 0) {
    f = f * -1;
    }
    while (f < 1.0) {
        f *= 10;
        *science = *science + 1;
    }
    *science = *science - 1;
}
