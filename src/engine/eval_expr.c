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
    char **arr = my_str_to_word_array(expr, "+-\n");
    char *res = "0";
    int len = 0;

    if (!arr || !arr[0])
        return NULL;
    len = my_strlen_tab(arr);
    for (int i = 0; i < len; i++)
        arr[i] = get_priority_result(info, arr[i]);
    res = my_strdup(arr[0]);
    if (!res)
        return NULL;
    for (int i = 1; i < len; i++) {
        res = my_strdup((info->last_op[i - 1] == ADD)
            ? calc_addition(res, arr[i]) : calc_substraction(res, arr[i]));
        if (!res)
            return NULL;
    }
    return res;
}

static void free_info(info_t *info)
{
    if (info->last_prio)
        free(info->last_prio);
    if (info->first_prio)
        free(info->first_prio);
}

static info_t *set_info(char *ops, char *expr)
{
    info_t *info = malloc(sizeof(info_t));

    if (!info)
        return NULL;
    info->last_prio = malloc(sizeof(char) * 4);
    info->first_prio = malloc(sizeof(char) * 5);
    if (!info->last_prio || !info->first_prio)
        return NULL;
    my_strncpy(info->last_prio, ops + 2, 2);
    my_strcpy(info->first_prio, ops + 4);
    info->last_prio[2] = '\n';
    info->last_prio[3] = '\0';
    info->first_prio[3] = '\n';
    info->first_prio[4] = '\0';
    info->last_op = get_last_op(expr, ops);
    return info;
}

char *eval_expr(char const *base, char *ops,
    char *expr, unsigned int size)
{
    info_t *info = set_info(ops, expr);
    char *res;

    if (!info || !info->last_prio || !info->first_prio || !info->last_op)
        return NULL;
    res = get_last_caluls(base, info, expr, size);
    free_info(info);
    return res;
}
