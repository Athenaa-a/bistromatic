/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_atoi
*/

#include <stdbool.h>

int my_atoi(const char *str)
{
    int result = 0;
    int tmp = 0;

    for (; *str; str++) {
        tmp = *str - '0';
        if (result > (__INT_MAX__ - tmp) / 10)
            return 3070;
        result = result * 10 + tmp;
    }
    return result;
}
