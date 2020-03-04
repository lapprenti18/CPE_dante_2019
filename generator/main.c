/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

int check_map_complet(char **map)
{
    for (int a = 0; map[a]; a++) {
        for (int b = 0; map[a][b]; b++) {
            if (map[a][b] == '.')
                return (84);
        }
    }
    return (0);
}

void perfecte_maze(int ac, char **av)
{
    int x = 0;
    int y = 0;
    char **map = malloc(sizeof(char *) * (atoi(av[2]) + 1));

    map[atoi(av[2])] = NULL;
    for (int a = 0; a < atoi(av[2]); a++) {
        map[a] = malloc(sizeof(char) * (atoi(av[1]) + 1));
        map[a][atoi(av[1])] = '\0';
        for (int b = 0; b < (atoi(av[1])) ; b++) {
            map[a][b] = 'X';
        }
    }
    map[0][0] = '*';
    map[atoi(av[2]) - 1][atoi(av[1]) - 1] = '*';
    for (int a = 0; map[a]; a++)
        printf("%s\n", map[a]);
}

void imperfecte_maze(int ac, char **av)
{
    return;
}

int main(int ac, char **av)
{
    if (ac > 4)
        return (84);
    if (ac == 4)
        imperfecte_maze(ac, av);
    perfecte_maze(ac, av);
    return (0);
}