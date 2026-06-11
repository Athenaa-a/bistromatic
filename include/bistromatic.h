/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** bistromatic
*/

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H

    #include <unistd.h>
    #include <stdlib.h>

    #define OP_OPEN_PARENT_IDX 0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX 2
    #define OP_SUB_IDX 3
    #define OP_NEG_IDX 3
    #define OP_MULT_IDX 4
    #define OP_DIV_IDX 5
    #define OP_MOD_IDX 6

    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"

typedef enum {
    OPN,
    CLS,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD
} op_t;

typedef struct {
    char *last_prio;
    char *first_prio;
    op_t *last_op;
    op_t *first_op;
} info_t;

//lib
void my_putchar(char const c);
void my_putstr(char const *str);
void my_put_error(char const *str);
void *my_realloc(void *pointer, size_t old_size, size_t new_size);
char **my_str_to_word_array(char *buf, char *sep);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_strlen(char const *str);
int my_atoi(char const *);
char *my_revstr(char *str);
char *my_int_to_str(int nb);
char *my_strncpy(char *dest, char const *src, int n);
int my_strlen_tab(char **tab);

//calcul
char *calc_substraction(char a[], char b[]);
char *calc_addition(char a[], char b[]);
char *my_strcat(char *dest, const char *src);
int my_strlen_tab(char **tab);

//calcul
char *calc_substraction(char a[], char b[]);
char *calc_addition(char a[], char b[]);
char *calc_multiplication(char a[], char b[]);

//parsing
int calc_occurences(char *expr);
char *eval_expr(char *ops, char *expr);
op_t *get_last_op(char *expr, char *ops);
op_t *get_first_op(char *expr, char *ops);

int bistromatic(int ac, char **av);

#endif
