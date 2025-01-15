/*
** EPITECH PROJECT, 2023
** hihu
** File description:
** ojojojo
*/
#include <stdarg.h>
#include "my.h"

int hexal_format(char type, va_list argp)
{
    int count = 0;

    if (type == 'x') {
        count += my_nbr_hexa(va_arg(argp, int));
        return 0;
    }
    if (type == 'X') {
        count += my_nbr_hexasupp(va_arg(argp, int));
        return 0;
    }
    if (type == 'o') {
        count += my_nbr_octal(va_arg(argp, long long int));
        return 0;
    }
    return 0;
}
