/*
** EPITECH PROJECT, 2018
** find_square
** File description:
** find_saque
*/

#include "../../include/bsq.h"

int column_size(char *str)
{
    int it = 0;
    int count = 0;

    while (str[it] != '\n')
        it++;
    it++;
    while (str[it] != '\n') {
        it++;
        count++;
    }
    return (count);
}

int size_of_square(int i, int j, char **tab)
{
    int b = 0;
    int line_size = my_strlen(tab[0]);
    
    int x = 1;
    if (tab[i][j] != '.')
        return (0);
    for (int y = 1; y < line_size && tab[i + y]; y = y + 1) {
        b = 0;
        while (b <= y) {
            if (tab[i + b][j + y] != '.' || tab[i + y][j + b] != '.')
                return (x);
            
            b = b + 1;
        }
        x = x + 1;
    }
    return (x);
}

char **tab_with_square(int i, int j, int x, char **tab)
{
    int it = 0;
    char **temp = tab;
    
    if (x == 1) {
        temp[i][j] = 'x';
        return (temp);
    } else if (x > 1) {
        for (int y = 0; y < x ; y++) {
            it = 0;
            while (it <= y) {
                temp[i + it][j + y] = 'x';
                temp[i + y][j + it] = 'x';
                it = it + 1;
            }
        }   
    }
    return (temp);
}

char **find_big_square(int line, int column, char **tab)
{
    char **save_tab = tab;
    char **temp = tab;
    int it = 0;
    int cursor = 0;
    int temp_size = 0;
    int save_i;
    int save_j;
    int temp_size_square = 1;
    while (cursor < (line - temp_size_square)) {
        for (it = 0; (column - temp_size_square) > it; it++) {
            if ((temp_size = size_of_square(cursor, it, tab)) > temp_size_square) {
                temp_size_square = temp_size;
                save_i = cursor;
                save_j = it;
            }
        }
        cursor = cursor + 1;
    }
    temp = tab_with_square(save_i, save_j, temp_size_square, tab);
    return (temp);
}
