/*
** EPITECH PROJECT, 2023
** erzteythg
** File description:
** dsefvd
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int digits_formatbisbis4(char type, va_list argp, int *where)
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

int digits_formatbisbis3(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'o') {
        (*where) += 2;
        my_putchar('0');
        count += my_nbr_octal(va_arg(argp, long long int));
        return 0;
    }
    if (type == 'd' || type == 'i') {
        (*where) += 2;
        count += my_putallnbr(va_arg(argp, int));
        return 0;
    } else {
        digits_formatbisbis4(type, argp, where);
    }
}

int digits_formatbisbis2(char type, va_list argp, int *where)
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
        digits_formatbisbis3(type, argp, where);
    }
    return count;
}

int digits_formatbisbis(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'x') {
        my_putstr("0x");
        (*where) += 2;
        count += my_nbr_hexa(va_arg(argp, int));
        return 0;
    }
    if (type == 'X') {
        (*where) += 2;
        my_putstr("0X");
        count += my_nbr_hexasupp(va_arg(argp, int));
        return 0;
    } else {
        digits_formatbisbis2(type, argp, where);
    }
}
