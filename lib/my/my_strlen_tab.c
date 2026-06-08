/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** tab_len
*/

int my_strlen_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return 0;
    for (; tab[i]; i++);
    return i;
}
