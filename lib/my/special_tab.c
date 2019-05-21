/*
** EPITECH PROJECT, 2018
** special_tab
** File description:
** tab_special_case
*/

#include "../../include/bsq.h"

int verif_tab_obs(char **tab)
{
    int line = 0;
    int column = 0;

    while (tab[line]) {
        column = 0;
        while (tab[line][column]) {
            if (tab[line][column] == '.')
                return (1);
            column++;
        }
        line++;
    }
    return (0);
}

char **one_point(char **tab)
{
    char **res = tab;

    if (res[0][0] == '.')
        res[0][0] = 'x';
    return (res);
}

char **my_column_square(char **tab)
{
    int b = 0;
    int it = 0;
    char **temp = tab;

    while (temp[b]) {
        if (it == 0 && temp[b][0] == '.') {
            temp[b][0] = 'x';
            it = it + 1;
        }
        b++;
    }
    return (temp);
}

char **my_str_square(char **tab)
{
    int line = 0;
    int column = 0;
    int it = 0;
    char **temp = tab;

    while (temp[line][column]) {
        if (it == 0 && temp[line][column] == '.') {
            temp[line][column] = 'x';
            it = it + 1;
        }
        column = column + 1;
    }
    return (temp);
}
