/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Functions handling the signs
*/

#include "bistromatic.h"
#include <stdio.h>

char *calc_signs(char *expr, char *ops)
{
    int minus_sign = 0;
    int plus_sign = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ops[2])
            plus_sign += 1;
        if (expr[i] == ops[3])
            minus_sign += 1;
    }
    if (minus_sign >= plus_sign)
        return &ops[3];
    else
        return &ops[2];
}
