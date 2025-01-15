/*
** EPITECH PROJECT, 2023
** rferza
** File description:
** ojojojo
*/
#include <stddef.h>
#include <unistd.h>
#include "my.h"

int my_nbr_hexa(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        my_putchar(nb + '0');
    }
    if (nb > 15) {
        my_nbr_hexa(nb / 16);
        my_nbr_hexa(nb % 16);
    }
    if ((nb >= 0) && (nb <= 9)) {
        my_putchar(nb + '0');
    }
    if ((nb > 9) && (nb < 16)) {
        my_putchar(nb + 87);
    }
}
