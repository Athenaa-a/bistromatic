/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** my_int_to_str
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "bistromatic.h"

int my_int_len(int nb)
{
    int len = 0;

    if (nb < 0)
        len++;
    for (; nb != 0; len++)
        nb /= 10;
    return len;
}

char *my_int_to_str(int nb)
{
    int len = my_int_len(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    int tmp = 0;
    bool neg = false;

    if (!res || len < 1)
        return NULL;
    if (nb < 0) {
        neg = true;
        res[len - neg] = '-';
        nb *= -1;
    }
    for (int i = 0; i < len - neg; i++) {
        tmp = nb % 10;
        nb /= 10;
        res[i] = tmp + '0';
    }
    res[len] = '\0';
    my_revstr(res);
    return res;
}
