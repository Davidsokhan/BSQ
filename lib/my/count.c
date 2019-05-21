/*
** EPITECH PROJECT, 2018
** count
** File description:
** count
*/
#include "../../include/bsq.h"

int my_strlen_enter(char *str)
{
    int it = 0;

    while (str[it] != '\n')
        it++;
    return (it);
}

int count_line(char **tab)
{
    int it = 0;

    while (tab[it])
        it++;
    return (it);
}

int my_strlen(char *str)
{
    int it = 0;

    while (str[it]) {
        it++;
    }
    return (it);
}
