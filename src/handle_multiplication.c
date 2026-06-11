/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function handling the additions
*/

#include "bistromatic.h"
#include <stdio.h>

char *mutliplication_loop(int multiplier, char *res, char *number)
{
    char *num_copy;
    char *tmp = NULL;

    for (int i = 1; i < multiplier; i++) {
        num_copy = my_strdup(number);
        tmp = calc_addition(res, num_copy);
        free(res);
        free(num_copy);
        res = tmp;
    }
    return res;
}

char *calc_multiplication(char a[], char b[])
{
    char *res = NULL;
    char *number;
    int multiplier = 0;

    if (my_strlen(a) <= my_strlen(b)) {
        multiplier = atoi(a);
        number = b;
    } else {
        multiplier = atoi(b);
        number = a;
    }
    if (multiplier == 0)
        return my_strdup("0");
    res = my_strdup(number);
    res = mutliplication_loop(multiplier, res, number);
    return res;
}
