/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Functions handling the parenthesis
*/

#include "bistromatic.h"

int calc_occurences(char *expr)
{
    int opened_par = 0;
    int closed_par = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            opened_par += 1;
        }
        if (expr[i] == ')')
            closed_par += 1;
    }
    if (opened_par != closed_par)
        return 1;
    else
        return 0;
}
