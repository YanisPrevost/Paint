/*
** EPITECH PROJECT, 2023
** mkfpzoejrezr
** File description:
** sfsdfsd
*/
#include <stddef.h>
#include <unistd.h>
#include "my.h"

int my_nbr_octal(long long int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        my_putchar(nb + '0');
    } else if (nb > 7) {
        my_nbr_octal(nb / 8);
        my_nbr_octal(nb % 8);
    } else {
        my_putchar(nb + '0');
    }
}
