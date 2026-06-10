/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** eval_expr
*/

#include "bistromatic.h"
#include <stdio.h>

char *get_priority_result(info_t *info, char *arg)
{
    char **arr = my_str_to_word_array(arg, info->first_prio);

    if (!arr || !arr[0])
        return NULL;
    if (!arr[1])
        return arr[0];
    return NULL;
}

char *get_last_caluls(char const *base, info_t *info,
    char *expr, unsigned int size)
{
    char **arr = my_str_to_word_array(expr, info->last_prio);
    int len = 0;

    if (!arr || !arr[0])
        return NULL;
    len = my_strlen_tab(arr);
    for (int i = 0; i < len; i++) {
        arr[i] = get_priority_result(info, arr[i]);
        my_putstr(arr[i]);
        my_putstr("\n");
    }
    return "nope";
}

static void free_info(info_t *info)
{
    if (info->last_prio)
        free(info->last_prio);
    if (info->first_prio)
        free(info->first_prio);
}

char *eval_expr(char const *base, char *ops,
    char *expr, unsigned int size)
{
    info_t info = {.last_prio = malloc(sizeof(char) * 4),
        .first_prio = malloc(sizeof(char) * 5)};

    if (!info.last_prio || !info.first_prio)
        return NULL;
    my_strncpy(info.last_prio, ops + 2, 2);
    my_strcpy(info.first_prio, ops + 4);
    info.last_prio[2] = '\n';
    info.last_prio[3] = '\0';
    info.first_prio[3] = '\n';
    info.first_prio[4] = '\0';
    get_last_caluls(base, &info, expr, size);
    free_info(&info);
    return "nope";
}
