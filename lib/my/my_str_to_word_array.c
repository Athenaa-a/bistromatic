/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_str_to_word_array
*/

#include "bistromatic.h"

static int is_sep(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

static int count_words(const char *str)
{
    int count = 0;
    int i;

    for (i = 0; str[i]; i++) {
        if (!is_sep(str[i]) && (i == 0 || is_sep(str[i - 1])))
            count++;
    }
    return count;
}

static char *dup_word(const char *str, int start, int end)
{
    char *word;
    int i;

    word = malloc(end - start + 1);
    if (!word)
        return NULL;
    for (i = 0; i < end - start; i++) {
        word[i] = str[start + i];
    }
    word[i] = '\0';
    return word;
}

char **my_str_to_word_array(const char *str)
{
    char **tab;
    int start = -1;
    int w = 0;

    tab = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!tab)
        return NULL;
    for (int i = 0;; i++) {
        if (str[i] && !is_sep(str[i]) && start < 0)
            start = i;
        if ((is_sep(str[i]) || !str[i]) && start >= 0) {
            tab[w] = dup_word(str, start, i);
            w++;
            start = -1;
        }
        if (!str[i])
            break;
    }
    tab[w] = NULL;
    return tab;
}
