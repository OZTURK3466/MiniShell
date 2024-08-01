/*
** EPITECH PROJECT, 2023
** task01
** File description:
** day07
*/
#include "../../include/my.h"

int my_put_nbr(long int nb)
{
    if (nb > INT_MAX || nb < INT_MIN)
        return 2147483647;
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return 0;
}
