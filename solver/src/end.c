/*
** EPITECH PROJECT, 2020
** solver.c
** File description:
** solver.c
*/

#include "../include/main.h"

int check_loose(solver_t *solver)
{
    int y = solver->y;
    int x = solver->x;

    if (solver->map[y][x + 1] == '*' || solver->map[y][x + 1] == '2')
        return (0);
    if (x > 0 && solver->map[y][x - 1] == '*' || x > 0 && solver->map[y]\
    [x - 1] == '2')
        return (0);
    if (solver->map[y + 1] != NULL && solver->map[y + 1][x] == '*'
    || solver->map[y + 1] != NULL && solver->map[y + 1][x] == '2')
        return (0);
    if (y > 0 && solver->map[y - 1][x] == '*' || y > 0 && solver->map[y - 1]\
    [x] == '2')
        return (0);
    no_sol();
}

int check_end(solver_t *solver)
{
    if (solver->x == solver->line_length - 1
    && solver->y == solver->nb_lines - 1) {
        replace_all(solver);
        print_map(solver);
        return (1);
    }
    check_loose(solver);

    return (0);
}
