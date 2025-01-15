/*
** EPITECH PROJECT, 2023
** efnqen
** File description:
** lezlrjez
*/

#include "my.h"

int count0(float *f, int *science)
{
    while (*f < 1.0) {
        *f *= 10;
        *science = *science + 1;
    }
    return 0;
}
