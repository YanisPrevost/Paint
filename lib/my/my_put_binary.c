/*
** EPITECH PROJECT, 2023
** myputnb
** File description:
** ngfrgfbg
*/
#include "my.h"

int my_put_binary(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 1) {
        my_put_binary(nb / 2);
        my_put_binary(nb % 2);
    } else {
        my_putchar(nb + '0');
    }
}
