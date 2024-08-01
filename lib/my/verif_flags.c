/*
** EPITECH PROJECT, 2023
** printf
** File description:
** verif_flags
*/
#include <stdarg.h>
#include "../../include/my.h"

int verif_flag_oct_hex(char s, va_list list)
{
    int arg_int = 0;

    if (s == 'X'){
        arg_int = va_arg(list, int);
        return my_putnbr_base(arg_int, "0123456789ABCDEF");
    }
    if (s == 'x'){
        arg_int = va_arg(list, int);
        return my_putnbr_base(arg_int, "0123456789abcdef");
    }
    if (s == 'o'){
        arg_int = va_arg(list, int);
        return my_putnbr_base(arg_int, "01234567");
    }
    return arg_int;
}

int verif_flags_other(char s)
{
    if (s == '%')
        my_putchar('%');
    if (s != 'c' && s != 's' && s != 'd' && s != 'i' && s != '%' && s != 'u'
    && s != 'x' && s != 'X' && s != 'o' && s != 'f' && s != 'F' && s != 'e'
    && s != 'E'){
        my_putchar('%');
        my_putchar(s);
    }
    return 0;
}

int verif_flags_int(char s, va_list list)
{
    int arg_int = 0;

    if (s == 'd' || s == 'i'){
        arg_int = va_arg(list, int);
        my_put_nbr(arg_int);
    }
    if (s == 'u') {
        arg_int = va_arg(list, int);
        unsigned_nbr(arg_int);
        return len_nbr(arg_int);
    }
    return arg_int;
}

static int verif_flags_float(char s, va_list list, int nb_str)
{
    float arg_float;

    if (s == 'f'){
        arg_float = va_arg(list, double);
        my_put_float(arg_float, nb_str, 'f');
        return len_nbr((int) arg_float) + 7;
    }
    if (s == 'F'){
        arg_float = va_arg(list, double);
        my_put_float(arg_float, nb_str, 'F');
        return len_nbr((int) arg_float) + 7;
    }
    return 0;
}

static int verif_flags_float2(char s, va_list list)
{
    float arg_float;

    if (s == 'e'){
        arg_float = va_arg(list, double);
        my_put_e(arg_float, 'e');
        return len_nbr((int) arg_float) + 7;
    }
    if (s == 'E'){
        arg_float = va_arg(list, double);
        my_put_e(arg_float, 'E');
        return len_nbr((int) arg_float) + 7;
    }
    return 0;
}

int verif_flags(char s, va_list list, int nb_str)
{
    char arg_char;
    char *arg_str;

    if (s == 'c'){
        arg_char = va_arg(list, int);
        my_putchar(arg_char);
    }
    if (s == 's'){
        arg_str = va_arg(list, char *);
        my_putstr(arg_str);
        return my_strlen(arg_str);
    }
    verif_flags_other(s);
    verif_flags_int(s, list);
    verif_flag_oct_hex(s, list);
    verif_flags_float(s, list, nb_str);
    verif_flags_float2(s, list);
    return 0;
}
