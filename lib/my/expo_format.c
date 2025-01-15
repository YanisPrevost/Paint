/*
** EPITECH PROJECT, 2023
** kjnkjhji
** File description:
** jkiujhji
*/

#include "my.h"
#include <stdarg.h>

int expo_format(char type, va_list argp)
{
    int count = 0;

    if (type == 'e') {
        count += my_expotentiel(va_arg(argp, double), 0, 0);
        return 0;
    }
    if (type == 'E') {
        count += my_expotentielsupp(va_arg(argp, double), 0, 0);
        return 0;
    }
    return count;
}
