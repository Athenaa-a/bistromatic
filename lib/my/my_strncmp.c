/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_strncmp
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int i;

    for (i = 0; i < n && s1[i] && s2[i] && (s1[i] == s2[i]); i++);
    if (i == n)
        return 0;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
