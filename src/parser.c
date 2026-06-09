/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function parsing file
*/

#include "bistromatic.h"
#include <string.h>
#include <stdlib.h>

void parse_args(int ac, char **av)
{
    if (!av[1] || !av[3] || ac > 4)
        print_usage(av);
    if (ac == 1 && !strcmp(av[1], "-h"))
        print_help();
    else if (strcmp(av[1], "-h") && my_strlen(av[1]) != 10)
        print_usage(av);
    else if (my_strlen(av[2]) != 7)
        print_usage(av);
}
