/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function handling the additions
*/

#include "bistromatic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *carry_handling(int carry, int idx, char *res)
{
    if (carry) {
        res = my_realloc(res, idx, idx + 2);
        res[idx] = '0' + carry;
        res[idx + 1] = '\0';
        idx++;
    }
    return res;
}

void fill_res(char *res, int idx, int temp)
{
    res[idx] = '0' + temp;
    res[idx + 1] = '\0';
}

static char *loop_for_zeros(char *res, int len, char a[], char b[])
{
    int carry = 0;
    int zero_a;
    int zero_b;
    int idx = 0;
    int temp = 0;

    for (; idx < len; idx++) {
        zero_a = (idx < my_strlen(a)) ? a[idx] - '0' : 0;
        zero_b = (idx < my_strlen(b)) ? b[idx] - '0' : 0;
        temp = zero_a - zero_b - carry;
        carry = 0;
        if (temp < 0) {
            temp = 10 - temp * -1;
            carry++;
        }
        res = my_realloc(res, idx, idx + 2);
        fill_res(res, idx, temp);
    }
    res = carry_handling(carry, idx, res);
    return res;
}

char *calc_substraction(char a[], char b[])
{
    int len = 0;
    char *res = NULL;

    if (my_strlen(a) < my_strlen(b))
        len = my_strlen(b);
    else
        len = my_strlen(a);
    my_revstr(a);
    my_revstr(b);
    res = loop_for_zeros(res, len, a, b);
    my_revstr(res);
    return res;
}
