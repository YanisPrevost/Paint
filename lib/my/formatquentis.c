/*
** EPITECH PROJECT, 2023
** erzteythg
** File description:
** dsefvd
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int digits_quentis4(char type, va_list argp, int *where)
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

int formatquentis3(char type, va_list argp, int *where)
{
    int count = 0;

    if ((type == 'd') || (type == 'i') || (type == 'u')) {
        (*where) += 2;
        if (type == 'u') {
            count += my_put_plusnbr(va_arg(argp, unsigned int));
            return 0;
        } else {
            count += my_put_plusnbr(va_arg(argp, int));
        }
    } else {
        digits_quentis4(type, argp, where);
    }
}

int formatquentis2(char type, va_list argp, int *where)
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
        formatquentis3(type, argp, where);
    }
}

int formatquentis(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'f') {
        (*where) += 2;
        count += my_plusfloat(va_arg(argp, double));
        return 0;
    }
    if (type == 'e') {
        (*where) += 2;
        count += my_plusexpotentiel(va_arg(argp, double), 0, 0);
        return 0;
    }
    if (type == 'E') {
        (*where) += 2;
        count += my_plusexpotentielsupp(va_arg(argp, double), 0, 0);
        return 0;
    } else {
        formatquentis2(type, argp, where);
    }
}
