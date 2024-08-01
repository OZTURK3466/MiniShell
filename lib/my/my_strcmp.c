/*
** EPITECH PROJECT, 2023
** day06
** File description:
** task06
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}
