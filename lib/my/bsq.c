/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#include "../../include/bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char *take_nbr_str(char *str)
{
    int size = my_strlen_enter(str);
    char *res = malloc(sizeof(char) * size + 1);
    int it = 0;

    while (str[it] != '\n') {
        res[it] = str[it];
        it++;
    }
    res[it] = '\0';
    return (res);
}

char **put_on_tab(char *str)
{
    char *temp = take_nbr_str(str);
    int it = my_strlen_enter(str) + 1;
    int line = 0;
    int column = 0;
    char **tab = malloc(sizeof(char *) * (my_getnbr(temp) + 1));

    while (line < my_getnbr(temp)) {
        column = 0;
        tab[line] = malloc(sizeof(char) * column_size(str) + 1);
        while (str[it] != '\n') {
            tab[line][column] = str[it];
            it++;
            column++;
        }
        it++;
        tab[line][column] = '\0';
        line++;
    }
    tab[line] = NULL;
    free(temp);
    return (tab);
}

char **file_on_tab(char *pathname)
{
    int fd = 0;
    struct stat byte;
    char *str_tab;
    char **tab;
    
    fd = open(pathname, O_RDONLY);
    stat(pathname, &byte);
    str_tab = malloc(sizeof(char) * byte.st_size);
    read(fd, str_tab, byte.st_size);
    tab = put_on_tab(str_tab);
    free(str_tab);
    return (tab);
}

char **bsq(char **tab)
{
    char **result;
    char **tab_line;
    int line;
    int column;
    
    if (verif_tab_obs(tab) == 0)
        return (tab);
    if (count_line(tab) == 1) {
        tab_line = my_str_square(tab);
        return (tab_line);
    }
    if (count_line(tab) == 1 && my_strlen(tab[0]) == 1) {
        tab_line = one_point(tab);
        return (tab_line);
    }
    if (my_strlen(tab[0]) == 1) {
        tab_line = my_column_square(tab);
        return (tab_line);
    }
    line = count_line(tab);
    column = my_strlen(tab[0]);
    result = find_big_square(line, column, tab);
    return (tab);
}
