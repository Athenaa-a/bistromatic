/*
** EPITECH PROJECT, 2026
** my_strcpy
** File description:
** Copies a string to another string
*/

#include "bistromatic.h"

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
