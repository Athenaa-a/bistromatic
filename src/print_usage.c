/*
** EPITECH PROJECT, 2026
** bistromatic
** File description:
** Function printing the usage i ncase of an error
*/

void print_usage(char **av)
{
    my_putstr("Usage: ");
    my_putstr(av[0]);
    my_putstr(" base ops\"()+-*/%\" exp_len\n");
}
