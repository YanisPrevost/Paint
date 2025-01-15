/*
** EPITECH PROJECT, 2023
** erzteythg
** File description:
** dsefvd
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int digits_formattris5(char type, va_list argp, int *where)
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

int formattris4(char type, va_list argp, int *where)
{
    int count = 0;

    if ((type == 'd') || (type == 'i') || (type == 'u')) {
        (*where) += 2;
        count += my_put_nbr(va_arg(argp, int));
        return 0;
    } else {
        digits_formattris5(type, argp, where);
    }
}

int formattris3(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'p') {
        my_putchar(' ');
        my_putstr("0x");
        (*where) += 2;
        count += my_nbr_hexasupp(va_arg(argp, int));
        return 0;
    }
    if (type == 'd' || type == 'i') {
        (*where) += 2;
        count += my_spaceputallnbr(va_arg(argp, int));
        return 0;
    } else {
        formattris4(type, argp, where);
    }
}

int formattris2(char type, va_list argp, int *where)
{
    int count = 0;

    if (type == 'f') {
        (*where) += 2;
        count += my_spacefloat(va_arg(argp, double));
        return 0;
    }
    if (type == 'e') {
        (*where) += 2;
        count += my_spaceexpotentiel(va_arg(argp, double), 0, 0);
        return 0;
    }
    if (type == 'E') {
        (*where) += 2;
        count += my_spaceexpotentielsupp(va_arg(argp, double), 0, 0);
        return 0;
    } else {
        formattris3(type, argp, where);
    }
}

int formattris(char type, va_list argp, int *where)
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
        formattris2(type, argp, where);
    }
}
