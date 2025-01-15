/*
** EPITECH PROJECT, 2023
** dksmfsmd
** File description:
** sdfdsfdsf
*/
#include <stdarg.h>
#include "my.h"

int string_format(char type, va_list argp)
{
    int count = 0;

    if (type == 'c') {
        count += my_putchar(va_arg(argp, int));
        return 0;
    }
    if (type == '%') {
        my_putchar('%');
        return 0;
    }
    if (type == 's') {
        count += my_putstr(va_arg(argp, char *));
        return 0;
    }
}
