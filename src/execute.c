/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** execute.c
*/

#include "../include/my.h"

char *concat_strings(const char *s1, const char *s2)
{
    size_t len_s1 = my_strlen(s1);
    size_t len_s2 = my_strlen(s2);
    char *result = malloc(len_s1 + len_s2 + 2);

    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    my_strcpy(result, s1);
    my_strcat(result, "/");
    my_strcat(result, s2);
    return result;
}

char *find_executable_path(char *command, char *path)
{
    char *cmd_path = NULL;
    char *token = strtok(path, ":");
    char *full_path;

    while (token != NULL) {
        full_path = concat_strings(token, command);
        if (access(full_path, X_OK) == 0) {
            cmd_path = full_path;
            break;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    return cmd_path;
}

static int error_handling(char **args)
{
    struct stat ed;

    stat(args[0], &ed);
    if (S_ISDIR(ed.st_mode)){
        my_printf("%s: Permission denied.\n", args[0]);
        exit(1);
    }
    return 0;
}

void execute_command(char **args, char **env, char *path)
{
    pid_t pid = fork();
    char *cmd_path;
    int status;

    if (pid < 0)
        exit(1);
    if (pid == 0) {
        error_handling(args);
        cmd_path = find_executable_path(args[0], path);
        if (cmd_path == NULL)
            exit(1);
        execve(cmd_path, args, env);
        perror("execve");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            return;
        exit(1);
    }
}

void handle_all_command(int num_args, char **args, char **env)
{
    if (num_args > 0) {
        if (my_strcmp(args[0], "exit") == 0)
            exit(EXIT_SUCCESS);
        if (my_strcmp(args[0], "cd") == 0)
            command_cd(num_args, args, env);
        if (my_strcmp(args[0], "setenv") == 0)
            command_setenv(num_args, args, env);
        if (my_strcmp(args[0], "unsetenv") == 0)
            command_unsetenv(num_args, args, env);
        if (my_strcmp(args[0], "env") == 0)
            command_env(env);
        else
            execute_command(args, env, my_getenv("PATH", env));
    }
}

static void handle_command_2(size_t cmd_count, char **commands, char **env)
{
    char *args[8192 / 2];
    int num_args;

    for (size_t i = 0; i < cmd_count; ++i) {
        if (my_strchr(commands[i], '|'))
            handle_pipeline(commands[i], env);
        else {
            num_args = parse_command
            (commands[i], args, sizeof(args) / sizeof(args[0]));
            handle_all_command(num_args, args, env);
        }
    }
}

void handle_command(char *cmd, char **env)
{
    char *commands[8192 / 2];
    char *single_cmd;
    size_t cmd_count = 0;

    single_cmd = strtok(cmd, ";");
    while (single_cmd != NULL) {
        if (cmd_count < sizeof(commands) / sizeof(commands[0]) - 1) {
            commands[cmd_count] = single_cmd;
            cmd_count++;
        }
        single_cmd = strtok(NULL, ";");
    }
    commands[cmd_count] = NULL;
    handle_command_2(cmd_count, commands, env);
}
