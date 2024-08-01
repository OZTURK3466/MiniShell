/*
** EPITECH PROJECT, 2023
** my_put_e
** File description:
** affichage pour le %e
*/

#include "../../include/my.h"

void plus(float nbr, char c)
{
    int count = 0;

    while ((long int) nbr > 9){
        nbr *= 0.1;
        count++;
    }
    my_put_float(nbr, 6, c - 1);
    my_putchar(c);
    my_putchar('+');
    if (count < 10){
        my_put_nbr(0);
        my_put_nbr(count);
    } else {
        my_put_nbr(count);
    }
}

void moins(float nbr, char c)
{
    long int int_p = nbr;
    int count = 0;

    while (int_p == 0){
        nbr *= 10;
        int_p = nbr;
        count++;
    }
    my_put_float(nbr, 6, c - 1);
    my_putchar(c);
    my_putchar('-');
    if (count < 10){
        my_put_nbr(0);
        my_put_nbr(count);
    } else {
        my_put_nbr(count);
    }
}

void my_put_e(float nbr, char c)
{
    if ((int) nbr == 0){
        moins(nbr, c);
    } else {
        plus(nbr, c);
    }
}
