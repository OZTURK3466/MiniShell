/*
** EPITECH PROJECT, 2023
** compute_power_rec
** File description:
** task04
*/

#include "../../include/my.h"

int len_nbr(int arg)
{
    int res = 0;

    if (arg < 0){
        arg *= -1;
        res++;
    }
    if (arg >= 0 && arg <= 9)
        return 1;
    while (arg > 0){
        arg /= 10;
        res++;
    }
    return res;
}
