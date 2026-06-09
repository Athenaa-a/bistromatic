/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** Reverse string
*/

#include "bistromatic.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char temp;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        i++;
    }
    return str;
}
