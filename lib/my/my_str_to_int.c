/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** my_str_to_int.c
*/

int my_str_to_int(const char *str)
{
    int resultat = 0;
    int signe = 1;

    if (*str == '-') {
        signe = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        resultat = resultat * 10 + (*str - '0');
        str++;
    }
    return signe * resultat;
}
