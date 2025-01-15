/*
** EPITECH PROJECT, 2023
** my_arrodi
** File description:
** arrondi la valeur donnee
*/

#include "my.h"

int my_arrondie(int n)
{
    int a = n;

    a = a % 10;
    if (a >= 5) {
        n = n + a;
    }
    return n;
}
