/*
** EPITECH PROJECT, 2023
** day06
** File description:
** task06
*/

#include "../../include/my.h"

char *my_strchr(char *str, int c)
{
    while (*str != '\0' && *str != (char)c) {
        str++;
    }
    if (*str == (char)c) {
        return (char *)str;
    }
    return NULL;
}
