/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Task02 Day04
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int len = 0; str[len] != '\0'; len++){
        write(1, &str[len], 1);
    }
    return (0);
}
