/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** command_env.c
*/

#include "../include/my.h"

void command_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
}

static int is_valid_env_name(const char *name)
{
    char c;

    if (name == NULL || *name == '\0') {
        return 0;
    }
    for (int i = 0; name[i] != '\0'; i++) {
        c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9') || c == '_')) {
            return 0;
        }
    }
    return 1;
}

static int env_var_exists(char *entry, const char *name)
{
    int j = 0;

    while (entry[j] != '\0' && entry[j] != '=') {
        if (entry[j] != name[j]) {
            return 0;
        }
        j++;
    }
    return (entry[j] == '=' && name[j] == '\0');
}

static int find_env_var_index(char **env, const char *name)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env_var_exists(env[i], name)) {
            return i;
        }
    }
    return -1;
}

static char *create_env_entry(const char *name, const char *value)
{
    size_t name_len = my_strlen(name);
    size_t value_len = my_strlen(value);
    char *entry = malloc(name_len + value_len + 2);

    if (entry == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    my_strcpy(entry, name);
    my_strcat(entry, "=");
    my_strcat(entry, value);
    return entry;
}

static void update_env_entry(char **env, const char *name, const char *value)
{
    int index = find_env_var_index(env, name);
    int num_vars = 0;

    if (index != -1) {
        env[index] = create_env_entry(name, value);
    } else {
        while (env[num_vars] != NULL)
            num_vars++;
        env[num_vars] = create_env_entry(name, value);
        env[num_vars + 1] = NULL;
    }
}

void command_setenv(int num_args, char **args, char **env)
{
    if (num_args < 2) {
        my_printf("Usage: setenv VARIABLE [VALUE]\n");
        return;
    }
    if (!is_valid_env_name(args[1])) {
        my_printf
        ("Error: Variable name must be alphanumeric or underscores only\n");
        return;
    }
    if (num_args == 2) {
        update_env_entry(env, args[1], "");
    } else {
        update_env_entry(env, args[1], args[2]);
    }
}

void command_unsetenv(int num_args, char **args, char **env)
{
    int index;

    if (num_args != 2) {
        my_printf("Usage: unsetenv VARIABLE\n");
        return;
    }
    if (!is_valid_env_name(args[1])) {
        my_printf
        ("Error: Variable name must be alphanumeric or underscores only\n");
        return;
    }
    index = find_env_var_index(env, args[1]);
    if (index != -1) {
        for (int i = index; env[i] != NULL; i++) {
            env[i] = env[i + 1];
        }
        my_printf("OK\n");
    } else {
        my_printf("KO: Error : line [%s] not found\n", args[1]);
    }
}
