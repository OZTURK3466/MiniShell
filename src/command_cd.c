/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** command_cd.c
*/

#include "../include/my.h"

int command_cd_dash(char **env)
{
    char *old_pwd = my_getenv("OLDPWD", env);

    if (old_pwd == NULL) {
        my_printf("cd: OLDPWD not set\n");
        return 1;
    }
    if (chdir(old_pwd) == -1) {
        my_printf("Not a directory.\n");
        return 1;
    }
    return 0;
}

int handle_cd_dash(char **args, char **env)
{
    if (my_strcmp(args[1], "-") == 0) {
        command_cd_dash(env);
    } else if (chdir(args[1]) == -1) {
        my_printf("Not a directory.\n");
        return 1;
    }
    return 0;
}

int command_cd(int num_args, char **args, char **env)
{
    char *home_dir = my_getenv("HOME", env);
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    if (num_args > 2) {
        my_printf("cd: Too many arguments.\n");
        return 1;
    }
    if (num_args == 2) {
        handle_cd_dash(args, env);
    } else {
        if (chdir(home_dir) == -1) {
            my_printf("Not a directory.\n");
            return (1);
        }
    }
    if (my_setenv("OLDPWD", cwd, 1, env) != 0) {
        my_printf("Error: Unable to set the OLDPWD environment variable.\n");
        return (1);
    }
}
