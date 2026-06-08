/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}
