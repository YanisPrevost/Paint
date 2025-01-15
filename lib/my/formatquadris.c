/*
** EPITECH PROJECT, 2023
** erzteythg
** File description:
** dsefvd
*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int digits_quadris4(char type, va_list argp, int *where)
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

int formatquadris3(char type, va_list argp, int *where)
{
    int count = 0;

    if ((type == 'd') || (type == 'i') || (type == 'u')) {
        (*where) += 2;
        if (type == 'u') {
            count += my_put_nbr(va_arg(argp, unsigned int));
            return 0;
        } else {
            count += my_put_nbr(va_arg(argp, int));
        }
        return 0;
    }
    if (type == 'p') {
        (*where) += 2;
        my_putstr("0x");
        count += my_nbr_hexa(va_arg(argp, double));
        return 0;
    } else {
        digits_quadris4(type, argp, where);
    }
}

int formatquadris2(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'f') {
        (*where) += 2;
        count += my_float(va_arg(argp, double));
        return 0;
    }
    if (type == 'e') {
        (*where) += 2;
        count += my_expotentiel(va_arg(argp, double), 0, 0);
        return 0;
    }
    if (type == 'E') {
        (*where) += 2;
        count += my_expotentielsupp(va_arg(argp, double), 0, 0);
        return 0;
    } else {
        formatquadris3(type, argp, where);
    }
}

int formatquadris(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'x') {
        (*where) += 2;
        count += my_nbr_hexa(va_arg(argp, int));
        return 0;
    }
    if (type == 'X') {
        (*where) += 2;
        count += my_nbr_hexasupp(va_arg(argp, int));
        return 0;
    }
    if (type == 'o') {
        (*where) += 2;
        count += my_nbr_octal(va_arg(argp, int));
        return 0;
    } else {
        formatquadris2(type, argp, where);
    }
}
