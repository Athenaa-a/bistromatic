/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_strdup
*/

#include "bistromatic.h"

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *dup = malloc(len + 1);

    if (!dup)
        return NULL;
    for (i = 0; i < len; i++) {
        dup[i] = src[i];
    }
    dup[i] = '\0';
    return dup;
}
