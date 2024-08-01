/*
** EPITECH PROJECT, 2023
** bsprintf
** File description:
** file .h
*/
#pragma once
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct {
    int prev_fd;
    int fd[2];
} pipe_info_t;

typedef struct {
    int current_index;
    int total_commands;
} command_info_t;

int my_put_nbr(long int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int verif_flags(char s, va_list list, int nb_str);
int my_putnbr_base(int nbr, char *base);
void my_put_float(double nbr, int nbr_decimal, char c);
int unsigned_nbr(unsigned int nb);
int my_printf(const char *format, ...);
int len_nbr(int arg);
void my_put_e(float nbr, char c);
int my_compute_power_rec(int nb, int p);
int my_getnbr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(const char *str1, const char *str2, size_t n);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcat_alloc(char *dest, char *src);
char *my_getenv(const char *name, char **env);
char *my_strchr(char *str, int c);
int my_setenv(char *name, char *value, int overwrite, char **env);
void handle_command(char *cmd, char **env);
int parse_command(char *cmd, char **args, int max_args);
char *my_strdup(char const *src);
void command_env(char **env);
void command_setenv(int num_args, char **args, char **env);
void command_unsetenv(int num_args, char **args, char **env);
int command_cd(int num_args, char **args, char **env);
void handle_pipeline(char *cmd, char **env);
void execute_command(char **args, char **env, char *path);
