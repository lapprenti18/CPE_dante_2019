/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../include/main.h"
#include "../include/function.h"

int my_solver(solver_t *solver);

void exit_on_error(solver_t *solver)
{
    if (solver->raw_map != NULL)
        free(solver->raw_map);
    if (solver->map != NULL)
        for (int i = 0; solver->map[i] != NULL; i++)
            free(solver->map[i]);
    printf("Please enter a valid map !\n");
    exit (84);
}

void fill_buffer(int ac, char *av[], solver_t *solver)
{
    struct stat st;
    int size = 0;
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        exit_on_error(solver);
    stat(av[1], &st);
    solver->raw_map = malloc(sizeof(char) * st.st_size + 1);
    size = read(fd, solver->raw_map, st.st_size + 1);
    solver->raw_map[size] = 0;
    solver->map = NULL;
    solver->x = 0;
    solver->y = 0;
}

int main(int ac, char *av[])
{
    solver_t solver;

    if (ac != 2) {
        printf("Please enter a maze to solve\n");
        return (84);
    } else {
        fill_buffer(ac, av, &solver);
        if (check_valid_file(&solver) == 84)
            exit_on_error(&solver);
        my_solver(&solver);
    }
    return (0);
}