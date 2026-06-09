/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** eval_expr
*/

#include "bistromatic.h"
#include <stdio.h>

char *get_priority_result(char *arg)
{
    char **arr = my_str_to_word_array(arg, "*/%\n");

    if (!arr || !arr[0])
        return NULL;
    if (!arr[1])
        return arr[0];
    return NULL;
}

char *eval_expr(char const *base, char const *ops,
    char *expr, unsigned int size)
{
    char **arr = my_str_to_word_array(expr, "+-'\n");
    int len = 0;

    if (!arr || !arr[0])
        return NULL;
    len = my_strlen_tab(arr);
    for (int i = 0; i < len; i++) {
        arr[i] = get_priority_result(arr[i]);
        my_putstr(arr[i]);
        my_putstr("\n");
    }
    return "nope";
}
