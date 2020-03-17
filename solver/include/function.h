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
} solver_t;

int check_valid_file(solver_t *solver);

#endif /* !FUNCTION_H_ */
