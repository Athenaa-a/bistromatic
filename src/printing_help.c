/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function printing -h
*/

#include "bistromatic.h"

void print_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "./calc base operators size_read\n\n", 33);
    write(1, "DESCRIPTION\n", 12);
    write(1, "- base: all the symbols of the base\n", 36);
    write(1, "- operators: the symbols for the parentheses and ", 49);
    write(1, "the 5 operators\n", 16);
    write(1, "- size_read: number of characters to be read\n", 45);
}
