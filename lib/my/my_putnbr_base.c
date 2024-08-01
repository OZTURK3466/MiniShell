/*
** EPITECH PROJECT, 2023
** putnbr_base
** File description:
** nbr_base
*/
#include "../../include/my.h"

int my_putnbr_base(int nbr, char *base)
{
    int a = 0;
    int len = 0;

    if (nbr > INT_MAX || nbr < INT_MIN)
        return 0;
    if (nbr < 0){
        my_putchar('-');
        len++;
        nbr *= -1;
    }
    if (nbr > 0){
        a = nbr % my_strlen(base);
        nbr /= my_strlen(base);
        len++;
        my_putnbr_base(nbr, base);
        my_putchar(base[a]);
    }
    return len;
}
