/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** getnbr
*/

#include "../../include/bistromatic.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long final = 0;

    while (str[i] == ' ' || str[i] == '\n')
        i++;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        final = final * 10 + (str[i] - '0');
        if (final * sign > 2147483647 || final * sign < -2147483648)
            return 0;
        i++;
    }
    return (int)(final * sign);
}
