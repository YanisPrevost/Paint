/*
** EPITECH PROJECT, 2023
** prophunt
** File description:
** ererere
*/
#include <stdarg.h>
#include "my.h"

int digits_format2(char type, va_list argp)
{
    int count = 0;

    if (type == 'f') {
        count += my_float(va_arg(argp, double));
        return 0;
    }
    if (type == 'b') {
        count += my_put_binary(va_arg(argp, long int));
        return 0;
    }
    if (type == 'p') {
        my_putstr("0x");
        count += my_nbr_hexa(va_arg(argp, int));
        return 0;
    }
    return count;
}

int digits_format(char type, va_list argp)
{
    int count = 0;

    if (type == 'd' || type == 'i') {
        count += my_putallnbr(va_arg(argp, int));
        return 0;
    }
    if (type == 'u') {
        count += my_putallnbr(va_arg(argp, unsigned int));
        return 0;
    }
    if (type == 'n') {
        return 0;
    } else {
        digits_format2(type, argp);
    }
    return count;
}
