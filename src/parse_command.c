/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** prompt.c
*/

#include "../include/my.h"

int parse_command(char *cmd, char **args, int max_args)
{
    int i = 0;
    char *token = strtok(cmd, " \t\n");

    while (token != NULL && i < max_args - 1) {
        args[i] = token;
        ++i;
        if (i < max_args - 1) {
            token = strtok(NULL, " \t\n");
        } else {
            break;
        }
    }
    args[i] = NULL;
    return i;
}
