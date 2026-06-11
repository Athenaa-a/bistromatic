/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** my_str_to_word_array
*/

#include <stdbool.h>
#include "bistromatic.h"

static bool is_sep(char c, char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (c == sep[i])
            return true;
    }
    return false;
}

int count_word(char *buf, char *sep)
{
    int count_nb_word = 0;

    for (int i = 0; buf[i]; i++) {
        if ((!is_sep(buf[i], sep) && is_sep(buf[i + 1], sep)) || (!buf[i + 1]))
            count_nb_word++;
    }
    return count_nb_word;
}

char *fill_word(char *buf, char *sep, int *k)
{
    int size_word = 0;
    char *word;

    while (buf[*k] != '\0' && is_sep(buf[*k], sep))
        (*k)++;
    if (buf[*k] == '\0')
        return NULL;
    while (buf[*k + size_word] != '\0' && !is_sep(buf[*k + size_word], sep))
        size_word++;
    word = malloc(sizeof(char) * (size_word + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < size_word; i++) {
        word[i] = buf[*k];
        (*k)++;
    }
    word[size_word] = '\0';
    return word;
}

char **my_str_to_word_array(char *buf, char *sep)
{
    int k = 0;
    int nb_word = count_word(buf, sep);
    char **arr = malloc(sizeof(char *) * (nb_word + 1));

    if (arr == NULL)
        return NULL;
    for (int i = 0; i < nb_word; i++) {
        arr[i] = fill_word(buf, sep, &k);
    }
    arr[nb_word] = NULL;
    return arr;
}
