/*
** EPITECH PROJECT, 2023
** task01
** File description:
** day07
*/
#include <stdio.h>
#include <limits.h>
#include "../../include/my.h"
#include <stdlib.h>

int negative(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '-')
            res++;
    }
    return ((res % 2 == 0) ? (1) : (-1));
}

long int factor(char const *str)
{
    long int res = 1;
    int i = 0;
    int j = 0;

    for (j = 0; str[j] < '0' || str[j] > '9'; j++){
    }
    i = j;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9'){
        res *= 10;
        i++;
    }
    return res / 10;
}

int my_getnbr(char const *str)
{
    long int mult = factor(str);
    int neg = negative(str);
    long int nb = 0;
    int i = 0;

    for (; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9' && '0' >= str[i + 1]){
            nb = nb + (str[i] - '0') * mult;
            mult /= 10;
        }
        if (str[i + 1] == '\0')
            return nb * neg;
        if (nb > INT_MAX)
            return 0;
    }
    return nb * neg;
}
