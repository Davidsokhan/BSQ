/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int error_gestion(int ac, char **av)
{
    struct stat byte;

    stat(av[1], &byte);
    if (byte.st_size == 0) {
        my_putstr("bad file\n");
        return (0);
    }
    if (ac != 2) {
        my_putstr("bad arg\n");
        return (0);
    }
    if (open(av[1], O_RDONLY) == -1) {
        my_putstr("no file to open\n");
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    char **tab;
    char **open;
    int it = 0;

    if (error_gestion(ac, av) == 0) {
        return (84);
    }
    open = file_on_tab(av[1]);
    tab = bsq(open);
    my_show_tab(tab);
    while (tab[it]) {
        free(tab[it]);
        it++;
    }
    free(tab);
    return (0);
}
