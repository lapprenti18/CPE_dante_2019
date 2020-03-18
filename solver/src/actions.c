/*
** EPITECH PROJECT, 2020
** actions.c
** File description:
** actions.c
*/

#include "../include/main.h"

void replace_all(solver_t *solver)
{
    int y = 0;
    int x = 0;

    for (y; solver->map[y] != NULL; y++) {
        for (x = 0; solver->map[y][x]; x++) {
            (solver->map[y][x] == '1') ? solver->map[y][x] = '*' : 0;
            (solver->map[y][x] == '2') ? solver->map[y][x] = 'o' : 0;
        }
    }
    solver->map[y - 1][x - 1] = 'o';
}

void go_back(solver_t *solver)
{
    solver->map[solver->y][solver->x] = '1';

    if (solver->x > 0 && solver->map[solver->y][solver->x - 1] == '2') {
        solver->x += -1;
        return;
    }
    if (solver->map[solver->y][solver->x + 1] == '2') {
        solver->x += 1;
        return;
    }
    if (solver->y > 0 && solver->map[solver->y - 1][solver->x] == '2') {
        solver->y += -1;
        return;
    }
    if (solver->map[solver->y + 1] != NULL
    && solver->map[solver->y + 1][solver->x] == '2') {
        solver->y += 1;
        return;
    }
}

void go_front(solver_t *solver)
{
    solver->map[solver->y][solver->x] = '2';

    if (solver->x > 0 && solver->map[solver->y][solver->x - 1] == '*') {
        solver->x += -1;
        return;
    }
    if (solver->map[solver->y][solver->x + 1] == '*') {
        solver->x += 1;
        return;
    }
    if (solver->y > 0 && solver->map[solver->y - 1][solver->x] == '*') {
        solver->y += -1;
        return;
    }
    if (solver->map[solver->y + 1] != NULL
    && solver->map[solver->y + 1][solver->x] == '*') {
        solver->y += 1;
        return;
    }
}