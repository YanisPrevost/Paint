/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** my_str_to_word_array.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <fcntl.h>

int is_alphanum(char c)
{
    if (c <= '!' || c >= 127)
        return (0);
    return (1);
}

char **str_to_word_array(char *str)
{
    int x = 0;
    int i = 0;
    int size = 0;
    char **arr = malloc(sizeof(char *) * (50));

    while (str[i] != '\0') {
        if (is_alphanum(str[i]))
            size++;
        if (is_alphanum(str[i]) == 1 && is_alphanum(str[i + 1]) == 0) {
            arr[x] = malloc(sizeof(char) * (size + 1));
            my_strcpy(arr[x], &str[i - size + 1]);
            size = 0;
            x++;
        }
        i++;
    }
    arr[x] = NULL;
    return arr;
}
