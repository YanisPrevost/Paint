/*
** EPITECH PROJECT, 2023
** my_compute_speit.c
** File description:
** power on a number but specialised
*/
int my_compute_speit(int nb, int p)
{
    int b;
    int i = nb;
    int j = p;

    if (j == 0) {
        return (1);
    }
    if (j < 0) {
        return (0);
    } else {
        for (b = 1; b < j; b++) {
            i = i * nb;
    }
    }
    return i;
}
