/*
** EPITECH PROJECT, 2023
** yt
** File description:
** rtr
*/
#include <stddef.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char i = 0;
    char scnt = my_strlen(dest);

    while (src[i] != '\0') {
        dest[scnt + i] = src[i];
        i = i + 1;
    }
    dest[scnt + i] = '\0';
    return dest;
}
