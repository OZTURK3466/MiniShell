/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** pip.c
*/

#include "../include/my.h"

void parse_commands(char *cmd, char **commands, int *num_commands)
{
    char *single_cmd = strtok(cmd, "|");

    *num_commands = 0;
    while (single_cmd != NULL) {
        commands[*num_commands] = single_cmd;
        (*num_commands)++;
        single_cmd = strtok(NULL, "|");
    }
}

static void create_pipe(pipe_info_t *pipe_info)
{
    if (pipe(pipe_info->fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

static void setup_child_process(pipe_info_t *pipe_info,
    command_info_t *cmd_info)
{
    if (pipe_info->prev_fd != 0) {
        dup2(pipe_info->prev_fd, STDIN_FILENO);
        close(pipe_info->prev_fd);
    }
    if (cmd_info->current_index < cmd_info->total_commands - 1) {
        dup2(pipe_info->fd[1], STDOUT_FILENO);
    }
    close(pipe_info->fd[0]);
}

void parse_and_execute_command(char *command,
    char **env, pipe_info_t *pipe_info, command_info_t *cmd_info)
{
    char *args[256];
    pid_t pid = fork();

    parse_command(command, args, sizeof(args) / sizeof(args[0]));
    if (pid == 0) {
        setup_child_process(pipe_info, cmd_info);
        execute_command(args, env, my_getenv("PATH", env));
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    waitpid(pid, NULL, 0);
}

static void close_unused_pipes(pipe_info_t *pipe_info)
{
    if (pipe_info->prev_fd != 0) {
        close(pipe_info->prev_fd);
    }
    close(pipe_info->fd[1]);
}

void execute_pipeline(char **commands, int num_commands, char **env)
{
    pipe_info_t pipe_info = {.prev_fd = 0};
    command_info_t cmd_info = {.total_commands = num_commands};

    for (cmd_info.current_index = 0;
    cmd_info.current_index < num_commands; cmd_info.current_index++) {
        create_pipe(&pipe_info);
        parse_and_execute_command
        (commands[cmd_info.current_index], env, &pipe_info, &cmd_info);
        close_unused_pipes(&pipe_info);
        pipe_info.prev_fd = pipe_info.fd[0];
    }
}

void handle_pipeline(char *cmd, char **env)
{
    char *commands[256];
    int num_commands;

    parse_commands(cmd, commands, &num_commands);
    execute_pipeline(commands, num_commands, env);
}
