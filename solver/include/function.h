/*
** EPITECH PROJECT, 2020
** function.h
** File description:
** function.h
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "main.h"

typedef struct solver_s
{
    char *raw_map;
    char **map;
    int x;
    int y;
    int line_length;
    int nb_lines;
} solver_t;

int check_valid_file(solver_t *solver);
void go_front(solver_t *solver);
void go_back(solver_t *solver);
void replace_all(solver_t *solver);
char **my_str_to_word_array(char *str, char separator);

#endif /* !FUNCTION_H_ */
