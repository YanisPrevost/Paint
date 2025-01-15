/*
** EPITECH PROJECT, 2023
** Projet8
** File description:
** ojojojo
*/

int my_strlen(char const *str)
{
    int cr = 0;

    while (str[cr] != '\0') {
        cr = cr + 1;
    }
    return (cr);
}
