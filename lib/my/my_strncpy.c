/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Day04 Task03
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    int i = 0;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > len)
        dest[i] = '\0';
    return dest;
}
