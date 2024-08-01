/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** main.c
*/

#include "../include/my.h"

int display_name(void)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
            my_printf("\033[1;34mShellTurk\033[0m");
            my_printf("\033[0;37m:\033[0m");
            my_printf("\033[1;36m~%s\033[0m", cwd);
            my_printf("\033[0;37m$ \033[0m");
    } else {
        perror("getcwd");
        return 84;
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    size_t length;

    if (argc != 1)
        return 84;
    while (1) {
        display_name();
        if (getline(&line, &len, stdin) == -1)
            break;
        length = my_strlen(line);
        if (length > 0 && line[length - 1] == '\n')
            line[length - 1] = '\0';
        handle_command(line, env);
    }
    free(line);
    return 0;
}
