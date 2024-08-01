/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini_printf project
*/
#include <stdarg.h>
#include <unistd.h>
#include "../../include/my.h"

int verif_formatting_f(const char *format, va_list list, int i)
{
    int nb_str = 0;

    if (format[i] == '%' && format[i + 1] == '.'
    && format[i + 2] >= '0' && format[i + 3] != '\0') {
        nb_str = format[i + 2] - '0';
        i += 3;
        verif_flags(format[i], list, nb_str);
    }
    return i;
}

void cond_if(char c, int arg)
{
    if (c == ' ' && arg >= 0)
        my_putchar(' ');
}

int verif_formatting_d(const char *format, va_list list, int i)
{
    int arg_int = 0;

    if (format[i] == '%' && (format[i + 1] == ' ' || format[i + 1] == '#'
    || format[i + 1] == '+' || format[i + 1] == '-') && (format[i + 2] == 'd'
    || format[i + 2] == 'i')){
        arg_int = va_arg(list, int);
        i++;
        cond_if(format[i], arg_int);
        if (arg_int < 0 && format[i] == '-'){
            my_putchar(format[i]);
            i++;
            my_put_nbr(arg_int * -1);
            return i;
        }
        if (arg_int > 0 && format[i] == '+')
            my_putchar(format[i]);
        i++;
        my_put_nbr(arg_int);
    }
    return i;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int len = 0;
    int nb_param = my_strlen(format);

    va_start(list, format);
    for (int i = 0; i < nb_param; i++){
        if (format[i] != '%'){
            my_putchar(format[i]);
            len++;
        }
        i = verif_formatting_d(format, list, i);
        if (format[i] == '%' && format[i + 1] != '.'){
            i++;
            len += verif_flags(format[i], list, 6);
        }
        i = verif_formatting_f(format, list, i);
    }
    return len - 1;
}
