/*
** EPITECH PROJECT, 2023
** ohhjhuh
** File description:
** hgtrfcvhjuy
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int pform4(char type, va_list argp, char *format, int *where)
{
    int count = 0;

    if (type == ' ') {
        formattris(format[(*where + 2)], argp, where);
        return 0;
    }
    if (type == '-') {
        formatquadris(format[(*where + 2)], argp, where);
        return 0;
    }
    if (type == '+') {
        formatquentis(format[(*where + 2)], argp, where);
        return 0;
    } else {
        write(2, &type, 1);
    }
}

int pform3(char type, va_list argp, char *format, int *where)
{
    int count = 0;

    if ((type == 'e') || (type == 'E')) {
        expo_format(type, argp);
        (*where)++;
        return 0;
    }
    if (type == 'b') {
        digits_format(type, argp);
        (*where)++;
        return 0;
    }
    if (type == '#') {
        digits_formatbisbis(format[(*where + 2)], argp, where);
        return 0;
    } else {
        pform4(type, argp, format, where);
    }
}

int pform2(char type, va_list argp, char *format, int *where)
{
    int count = 0;

    if ((type == 'u') || (type == 'f') || (type == 'p')) {
        digits_format(type, argp);
        (*where)++;
        return 0;
    }
    if ((type == 'd') || (type == 'i') || (type == 'n')) {
        digits_format(type, argp);
        (*where)++;
        return 0;
    }
    if (type == 'l') {
        digits_formatbis(format[(*where + 2)], argp, where);
        return 0;
    } else {
        pform3(type, argp, format, where);
    }
}

int pform(char type, va_list argp, char *format, int *where)
{
    int count = 0;

    if ((type == 'c') || (type == '%') || (type == 's')) {
        string_format(type, argp);
        (*where)++;
        return 0;
    }
    if ((type == 'x') || (type == 'X') || (type == 'o')) {
        hexal_format(type, argp);
        (*where)++;
        return 0;
    } else {
        pform2(type, argp, format, where);
    }
    return 0;
}

int my_printf(char *format, ...)
{
    va_list argp;
    int count = 0;
    int where = 0;
    char *format0 = format;

    va_start(argp, format);
    while (format0[where] != '\0') {
        if (format0[where] == '%') {
            pform((format0[where + 1]), argp, format, &where);
        } else {
            count += write(1, format0 + where, 1);
        }
        where++;
    }
    va_end(argp);
    return 0;
}
