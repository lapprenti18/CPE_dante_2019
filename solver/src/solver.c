/*
** EPITECH PROJECT, 2020
** solver.c
** File description:
** solver.c
*/

#include "../include/main.h"

char **my_str_to_word_array(char *str, char separator);

void print_map(solver_t *solver)
{
    int i = 0;

    for (i; solver->map[i + 1]; i++) {
        puts(solver->map[i]);
    }
    printf("%s", solver->map[i]);
}

int check_neighbour(solver_t *solver)
{
    if (solver->x > 0 && solver->map[solver->y][solver->x - 1] == '*')
        return (1);
    if (solver->map[solver->y][solver->x + 1] == '*')
        return (1);
    if (solver->y > 0 && solver->map[solver->y - 1][solver->x] == '*')
        return (1);
    if (solver->map[solver->y + 1] != NULL && solver->map[solver->y + 1][solver->x] == '*')
        return (1);

    return (0);
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
    if (solver->map[solver->y + 1] != NULL && solver->map[solver->y + 1][solver->x] == '2') {
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
    if (solver->map[solver->y + 1] != NULL && solver->map[solver->y + 1][solver->x] == '*') {
        solver->y += 1;
        return;
    }
}

void get_nb_lines(solver_t *solver)
{
    int i = 0;
    int j = 0;
    solver->nb_lines = 0;
    solver->line_length = 0;

    for (j; solver->map[i][j]; j++);
    solver->line_length = j;

    for (i; solver->map[i] != NULL; i++);
    solver->nb_lines = i;
}

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

int check_end(solver_t *solver)
{
    if (solver->x == solver->line_length - 1 && solver->y == solver->nb_lines - 1) {
        replace_all(solver);
        print_map(solver);
        return (1);
    }

    return (0);
}

int my_solver(solver_t *solver)
{
    int i = 0;
    int j = 0;

    solver->map = my_str_to_word_array(solver->raw_map, '\n');
    get_nb_lines(solver);

    while ("ricard") {
        if (check_neighbour(solver) == 1) {
            go_front(solver);
        } else {
            go_back(solver);
        }
        if (check_end(solver) == 1) {
            break;
        }
    }
    return (0);
}