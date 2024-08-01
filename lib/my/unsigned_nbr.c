/*
** EPITECH PROJECT, 2023
** printf
** File description:
** u
*/
#include "../../include/my.h"

int unsigned_nbr(unsigned int nb)
{
    if (nb > UINT_MAX)
        return 0;
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
