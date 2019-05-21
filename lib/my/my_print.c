/*
** EPITECH PROJECT, 2018
** my_print
** File description:
** my print
*/

#include "../../include/bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int it = 0;

    while (str[it]) {
        my_putchar(str[it]);
        it++;
    }
}

void my_show_tab(char **tab)
{
    int it = 0;

    while (tab[it]) {
        my_putstr(tab[it]);
        my_putchar('\n');
        it++;
    }
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int a = 0;
    int x = 0;

    if (str[a] == '-')
        a++;
    while (str[a] != '\0') {
        if (str[a] >= '0' && str[a] <= '9') {
            if (x != 0) {
                nbr = nbr * 10;
            }
            nbr = nbr + str[a] - 48;
            x = x + 1;
        }
        a = a + 1;
    }
    if (str[0] == '-'){
        nbr = nbr * -1;
    }
    return (nbr);
}
