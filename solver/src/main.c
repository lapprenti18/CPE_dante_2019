/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../include/main.h"

int main(int ac, char *av[])
{
    if (ac != 2) {
        printf("Please enter a maze to solve\n");
        return (84);
    } else {
        if (check_valid_file(av[1]) == 84)
            return (84);
        solver(av[1]);
    }
    return (0);
}