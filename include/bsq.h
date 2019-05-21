/*
** EPITECH PROJECT, 2018
** bsq_h
** File description:
** bsq h
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
void my_putstr(char *str);
void my_show_tab(char **tab);
int my_getnbr(char *str);
int verif_tab_obs(char **tab);
int column_size(char *str);
int size_of_square(int i, int j, char **tab);
char **my_column_square(char **tab);
char **one_point(char **tab);
char **tab_with_square(int i, int j, int x, char **tab);
char **find_big_square(int line, int column, char **tab);
char **my_str_square(char **tab);
int my_strlen_enter(char *str);
int count_line(char **tab);
int my_strlen(char *str);
char *take_nbr_str(char *str);
char **put_on_tab(char *str);
char **file_on_tab(char *pathname);
char **bsq(char **tab);
int error_gestion(int ac, char **av);
int right_tab(char **tab);
int main(int ac, char **av);

#endif