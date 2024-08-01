/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** put_float
*/

#include "../../include/my.h"

double positive(double nbr)
{
    if (nbr < 0){
        my_putchar('-');
        nbr *= -1;
        return nbr;
    }
    return nbr;
}

void boucle_while(double nbr, int nbr_decimal)
{
    long int_part = nbr;
    int a = my_compute_power_rec(10, nbr_decimal);
    long dec_part_int = (nbr - int_part) * a;
    int len_nb = len_nbr(dec_part_int);

    while (len_nb < nbr_decimal){
        len_nb++;
        my_put_nbr(0);
    }
    my_put_nbr(dec_part_int);
}

void my_put_float(double nbr, int nbr_decimal, char c)
{
    double new_nbr = positive(nbr);
    long int_part = (long) new_nbr;

    if (nbr > FLT_MAX || nbr < FLT_MIN){
        if (c == 'f')
            my_putstr("inf");
        if (c == 'F')
            my_putstr("INF");
        return;
    }
    if (nbr_decimal < 0 || nbr_decimal > 6)
        nbr_decimal = 6;
    if (nbr_decimal == 0){
        my_put_nbr(int_part);
        return;
    }
    my_put_nbr(int_part);
    my_putchar('.');
    boucle_while(new_nbr, nbr_decimal);
}
