/*
** EPITECH PROJECT, 2023
** putnbr_base
** File description:
** nbr_base
*/
#include "../../include/my.h"

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        if (str1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
