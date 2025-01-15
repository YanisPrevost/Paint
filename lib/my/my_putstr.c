/*
** EPITECH PROJECT, 2023
** Projet7
** File description:
** ojojojo
*/

#include <stdio.h>
#include "my.h"

int my_putstr(char const *str)
{
    int cr = 0;

    while (str[cr] != '\0') {
        my_putchar(str[cr]);
        cr = cr + 1;
    }
}
