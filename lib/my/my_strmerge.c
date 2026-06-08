/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** my_strmerge
*/

#include "bistromatic.h"

char *my_strmerge(char *str1, char *str2)
{
    char *result;
    int len1;
    int len2;

    if (!str1 || !str2)
        return NULL;
    len1 = my_strlen(str1);
    len2 = my_strlen(str2);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;
    my_strcpy(result, str1);
    my_strcat(result, str2);
    return result;
}
