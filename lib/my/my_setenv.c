/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Task02 Day04
*/

#include "../../include/my.h"

int add_env_entry(char **env, char *env_entry)
{
    if (env == NULL) {
        env = (char **)malloc(sizeof(char *));
        if (env == NULL) {
            free(env_entry);
            return -1;
        }
        *env = NULL;
    }
    env = env;
    while (*env != NULL) {
        env++;
    }
    *env = env_entry;
    *(env + 1) = NULL;
    return 0;
}

int setenv_or_update_env_entry(char *name, char *value,
    int overwrite, char **env)
{
    size_t len_name = my_strlen(name);
    size_t len_values = my_strlen(value);
    size_t len_total = len_name + len_values + 2;
    char *env_entry = (char *)malloc(len_total);

    if (my_strncmp(*env, name, len_name) == 0 && (*env)[len_name] == '=') {
        if (!overwrite) {
            return 0;
        } else {
            my_strcpy(env_entry, name);
            my_strcat(env_entry, "=");
            my_strcat(env_entry, value);
            *env = env_entry;
            return 0;
        }
    }
    return 0;
}

int my_setenv(char *name, char *value, int overwrite, char **env)
{
    size_t len_name = my_strlen(name);
    size_t len_values = my_strlen(value);
    size_t len_total = len_name + len_values + 2;
    char *env_entry = (char *)malloc(len_total);

    if (name == NULL || *name == '\0' || my_strchr(name, '=') != NULL)
        return -1;
    while (*env != NULL) {
        setenv_or_update_env_entry(name, value, overwrite, env);
        env++;
    }
    if (env_entry == NULL)
        return -1;
    my_strcpy(env_entry, name);
    my_strcat(env_entry, "=");
    my_strcat(env_entry, value);
    add_env_entry(env, env_entry);
    return 0;
}
