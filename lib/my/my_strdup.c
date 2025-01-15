/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *source)
{
    size_t length = my_strlen(source) + 1;
    char *duplicate = malloc(length);

    if (duplicate == NULL) {
        return NULL;
    }
    my_strcpy(duplicate, source);
    return duplicate;
}
