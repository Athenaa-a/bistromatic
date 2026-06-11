/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** eval_expr
*/

#include "bistromatic.h"
#include <stdio.h>

void free_tab(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

static char *choose_calc(info_t *info, char **arr)
{
    int len = 0;
    char *res = "0";

    if (!arr || !arr[0])
        return "0";
    len = my_strlen_tab(arr);
    res = my_strdup(arr[0]);
    if (!res)
        return "0";
    for (int i = 1; i < len; i++) {
        res = my_strdup((info->first_op[i - 1] == MUL)
            ? calc_multiplication(res, arr[i]) : "0");
        if (!res)
            return "0";
    }
    return res;
}

char *get_priority_result(info_t *info, char *arg)
{
    char **arr = my_str_to_word_array(arg, info->first_prio);
    char *res = "0";

    if (!arr || !arr[0])
        return NULL;
    if (!arr[1]) {
        res = my_strdup(arr[0]);
        free_tab(arr);
        return res;
    }
    info->first_op = get_first_op(arg, info->first_prio);
    res = choose_calc(info, arr);
    free_tab(arr);
    free(info->first_op);
    return res;
}

char *get_last_caluls(info_t *info, char *expr)
{
    char **arr = my_str_to_word_array(expr, info->last_prio);
    char *res = "0";
    int len = 0;

    if (!arr || !arr[0])
        return "0";
    len = my_strlen_tab(arr);
    for (int i = 0; i < len; i++)
        arr[i] = get_priority_result(info, arr[i]);
    res = my_strdup(arr[0]);
    if (!res)
        return "0";
    for (int i = 1; i < len; i++) {
        res = my_strdup((info->last_op[i - 1] == ADD)
            ? calc_addition(res, arr[i]) : calc_substraction(res, arr[i]));
        if (!res)
            return "0";
    }
    free_tab(arr);
    return res;
}

static void free_info(info_t *info)
{
    if (!info)
        return;
    if (info->last_prio)
        free(info->last_prio);
    if (info->first_prio)
        free(info->first_prio);
    if (info->last_op)
        free(info->last_op);
    free(info);
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
    info->first_op = NULL;
    return info;
}

char *eval_expr(char *ops, char *expr)
{
    info_t *info = set_info(ops, expr);
    char *res;

    if (!info || !info->last_prio || !info->first_prio || !info->last_op)
        return NULL;
    res = get_last_caluls(info, expr);
    free_info(info);
    return res;
}
