/*
** EPITECH PROJECT, 2025
** organized
** File description:
** my_strcmp
*/

#include "bistromatic.h"
#include <stdbool.h>

bool my_strcmp(char *str, char *name)
{
    int i = 0;

    while (str[i] == name[i] && str[i] != '\0' && name[i] != '\0') {
        i++;
    }
    if (str[i] != name[i])
        return false;
    else
        return true;
}
