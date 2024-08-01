/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Day04 Task03
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int len;

    len = 0;
    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return (len);
}
