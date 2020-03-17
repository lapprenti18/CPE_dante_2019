/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

char **perfecte_maze(int ac, char **av)
{
    char **map = malloc(sizeof(char *) * (atoi(av[2]) + 1));

    map[atoi(av[2])] = NULL;
    for (int a = 0; a < atoi(av[2]); a++) {
        map[a] = malloc(sizeof(char) * (atoi(av[1]) + 1));
        map[a][atoi(av[1])] = '\0';
        for (int b = 0; b < (atoi(av[1])) ; b++) {
            map[a][b] = 'X';
        }
    }
    return (map);
}

char **imperfecte_maze(char **map)
{
    int rand;

    for (int a = 0; map[a]; a++) {
        for (int b = 0; map[a][b]; b++) {
            if (map[a][b] == 'X') {
                rand += 1;
                (rand % 5) == 0 ? map[a][b] = '*' : 0;
            }
        }
    }
    return (map);
}

char **generate(char **map, generator_t *noeud, char *av[])
{
    int check_x = atoi(av[2]);
    int check_y = atoi(av[1]);

    while (noeud) {
        map[noeud->y][noeud->x] = '*';
        if (check_neibors(map, noeud) != 0) {
            creuse(map, noeud, check_x, check_y);
            noeud = noeud->next;
        } else {
            noeud = noeud->previous;
            if (noeud)
                noeud->next = NULL;
        }
    }
    return (map);
}

int main(int ac, char **av)
{
    char **map;
    generator_t noeud;
    int a = 0;

    srand(time(NULL));
    noeud.x = 0;
    noeud.y = 0;
    noeud.next = NULL;
    noeud.previous = NULL;
    if (ac > 4 || ac < 3)
        return (84);
    map = perfecte_maze(ac, av);
    map = generate(map, &noeud, av);
    if (ac == 4)
        map = imperfecte_maze(map);
    for (; map[a + 1]; a++)
        printf("%s\n", map[a]);
    printf("%s", map[a]);
    return (0);
}