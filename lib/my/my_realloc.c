/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function reallocating the memory
*/

#include <stdlib.h>

void *my_realloc(void *pointer, size_t old_size, size_t new_size)
{
    void *new_p = malloc(new_size);
    char *src = pointer;
    char *dest = new_p;

    if (!new_p)
        return NULL;
    for (size_t i = 0; i < old_size; i++)
        dest[i] = src[i];
    free(pointer);
    return new_p;
}