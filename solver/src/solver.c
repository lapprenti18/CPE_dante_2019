/*
** EPITECH PROJECT, 2020
** solver.c
** File description:
** solver.c
*/

#include "../include/main.h"

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
    if (solver->map[solver->y][solver->x + 1] == '*')
        return (1);
    if (solver->x > 0 && solver->map[solver->y][solver->x - 1] == '*')
        return (1);
    if (solver->map[solver->y + 1] != NULL
    && solver->map[solver->y + 1][solver->x] == '*')
        return (1);
    if (solver->y > 0 && solver->map[solver->y - 1][solver->x] == '*')
        return (1);

    return (0);
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

void no_sol(void)
{
    printf("no solution found");
    exit(0);
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