/*
** EPITECH PROJECT, 2023
** task02
** File description:
** day07
*/

#include "../../include/my.h"

char *my_strcat_alloc(char *s1, char *s2)
{
    int len_a = my_strlen(s1);
    int len_b = my_strlen(s2);
    int total_len = len_a + len_b;
    char *new = malloc(sizeof(char) * (total_len + 1));
    int i = 0;

    for (; i < len_a; i++)
        new[i] = s1[i];
    for (int j = 0; j < len_b; j++) {
        new[i] = s2[j];
        i++;
    }
    new[i] = '\0';
    return new;
}
