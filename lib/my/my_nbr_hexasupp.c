/*
** EPITECH PROJECT, 2023
** ldjzerjez
** File description:
** ezrezrezrz
*/
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int my_nbr_hexasupp(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        my_putchar(nb + '0');
    }
    if (nb > 15) {
        my_nbr_hexasupp(nb / 16);
        my_nbr_hexasupp(nb % 16);
    }
    if ((nb >= 0) && (nb <= 9)) {
        my_putchar(nb + '0');
    }
    if ((nb > 9) && (nb < 16)) {
        my_putchar(nb + 55);
    }
}
