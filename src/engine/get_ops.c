/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** get_ops
*/

#include "bistromatic.h"

op_t *fill_last_ops(char *expr, char *ops, int len, int index)
{
    op_t *op = malloc(sizeof(op_t) * len);

    if (!op)
        return NULL;
    for (int i = 0; expr[i] && index < len; i++) {
        if (expr[i] == ops[2]) {
            op[index] = ADD;
            index++;
        }
        if (expr[i] == ops[3]) {
            op[index] = SUB;
            index++;
        }
    }
    return op;
}

op_t *fill_first_ops(char *expr, char *ops, int len, int index)
{
    op_t *op = malloc(sizeof(op_t) * len);

    if (!op)
        return NULL;
    for (int i = 0; expr[i] && index < len; i++) {
        if (expr[i] == ops[0]) {
            op[index] = MUL;
            index++;
        }
        if (expr[i] == ops[1]) {
            op[index] = DIV;
            index++;
        }
        if (expr[i] == ops[2]) {
            op[index] = MOD;
            index++;
        }
    }
    return op;
}

op_t *get_last_op(char *expr, char *ops)
{
    int len = 0;
    int index = 0;

    if (!expr || !ops)
        return NULL;
    for (int i = 0; expr[i]; i++)
        if (expr[i] == ops[2] || expr[i] == ops[3])
            len++;
    return fill_last_ops(expr, ops, len, index);
}

op_t *get_first_op(char *expr, char *ops)
{
    int len = 0;
    int index = 0;

    if (!expr || !ops)
        return NULL;
    for (int i = 0; expr[i]; i++)
        if (expr[i] == ops[0] || expr[i] == ops[1] || expr[i] == ops[2])
            len++;
    return fill_first_ops(expr, ops, len, index);
}
