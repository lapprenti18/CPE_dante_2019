/*
** EPITECH PROJECT, 2020
** check_valid_file.c
** File description:
** check_valid_file.c
*/

#include "../include/main.h"

int check_valid_file3(char *buffer)
{
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n')
            return (84);
    }

    return (0);
}

int check_valid_file2(char *buffer)
{
    if (buffer[0] != '*' || buffer[strlen(buffer) - 1] != '*') {
        printf("Please enter a valid map !\n");
        return (84);
    }

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n') {
            return (84);
        }
    }

    if (check_valid_file3(buffer) == 84) {
        return (84);
    }

    return (0);
}

int check_valid_file(solver_t *solver)
{
    if (check_valid_file2(solver->raw_map) == 84) {
        return (84);
    }
    return (0);
}