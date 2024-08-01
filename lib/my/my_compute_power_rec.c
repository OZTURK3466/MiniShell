/*
** EPITECH PROJECT, 2023
** compute_power_rec
** File description:
** task04
*/
#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0 || p > 12)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return nb * my_compute_power_rec(nb, (p - 1));
}
