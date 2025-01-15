/*
** EPITECH PROJECT, 2023
** Projet12
** File description:
** ojojojo
*/
#include <stddef.h>

char my_strncpy(char *dest, const char *src, int n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    for (; i < n; ++i) {
        dest[i] = '\0';
    }
}
