/*
** EPITECH PROJECT, 2023
** zerbfgdsf
** File description:
** dsefvd
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int digits_formatbis2(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 's') {
        (*where) += 2;
        count += my_putstr(va_arg(argp, char *));
        return 0;
    }
    if (type == 'c') {
        (*where) += 2;
        count += my_putchar(va_arg(argp, int));
        return 0;
    } else {
        return count;
    }
}

int digits_formatbis(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'i') {
        (*where) += 2;
        my_putallnbr(va_arg(argp, long int));
    } else if (type == 'd') {
        (*where) += 2;
        count += my_putallnbr(va_arg(argp, long signed int));
    } else {
        digits_formatbis2(type, argp, where);
    }
}
