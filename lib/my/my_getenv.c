/*
** EPITECH PROJECT, 2023
** task01
** File description:
** day07
*/

#include "../../include/my.h"

char *my_getenv(const char *name, char **env)
{
    int i = 0;
    int len = my_strlen(name);

    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            return env[i] + len + 1;
        }
        i++;
    }
    return NULL;
}
