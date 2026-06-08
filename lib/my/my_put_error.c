/*
** EPITECH PROJECT, 2026
** my_put_error.c
** File description:
** my_put_error
*/

#include "bistromatic.h"

int my_put_error(char *str)
{
    if (!str)
        return 1;
    write(2, str, my_strlen(str));
    return 1;
}
