/*
** EPITECH PROJECT, 2026
** my_put_error.c
** File description:
** my_put_error
*/

#include "bistromatic.h"

void my_put_error(char const *str)
{
    if (!str)
        return;
    write(2, str, my_strlen(str));
}
