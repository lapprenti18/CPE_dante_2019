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

int randoz(int a)
{
    srand(time(NULL));
    return (rand()%a);
}

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

void imperfecte_maze(int ac, char **av)
{
    return;
}

int check_creusage(int x, int y, char **map, generator_t *noeud)
{
    if (y < 0 || x < 0 || !map[y] || !map[y][x])
        return (0);
    if (map[y][x] == '*')
        return (0);
    if (!(noeud->y == y && noeud->x == x + 1) && map[y][x + 1] == '*')
        return (0);
    if (!(noeud->y == y && noeud->x == x - 1) && x != 0 && map[y][x - 1] == '*')
        return (0);
    if (!(noeud->y == y + 1 && noeud->x == x) && map[y + 1] && map[y + 1][x] == '*')
        return (0);
    if (!(noeud->y == y - 1 && noeud->x == x) && y != 0 && map[y - 1][x] == '*')
        return (0);
    return (1);
}

int check_neibors(char **map, generator_t *noeud)
{
    if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
        return (1);
    if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
        return (1);
    if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
        return (1);
    if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
        return (1);
    return (0);
}

void add_noeud(int x, int y, generator_t **noeud)
{
    generator_t *new = malloc(sizeof(generator_t));
    generator_t *save = *noeud;

    new->x = x;
    new->y = y;
    new->next = NULL;
    while (save->next)
        save = save->next;
    save->next = new;
    new->previous = save;
}

void creuse(char **map, generator_t *noeud, int check_x, int check_y)
{
    int order = rand() % 4;

    if (noeud->x == check_x - 2 && noeud->y == check_y - 1 && map[check_y - 1][check_x - 1] == 'X')
        return (add_noeud(check_x - 1, check_y - 1, &noeud));
    if (noeud->x == check_x - 1 && noeud->y == check_y - 2 && map[check_y - 1][check_x - 1] == 'X')
        return (add_noeud(check_x - 1, check_y - 1, &noeud));
    if (order == 0) {
        if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x + 1, noeud->y, &noeud));
        if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x - 1, noeud->y, &noeud));
        if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y - 1, &noeud));
        if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y + 1, &noeud));
    }
    if (order == 1) {
        if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y + 1, &noeud));
        if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x + 1, noeud->y, &noeud));
        if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x - 1, noeud->y, &noeud));
        if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y - 1, &noeud));
    }
    if (order == 2) {
        if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y - 1, &noeud));
        if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y + 1, &noeud));
        if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x + 1, noeud->y, &noeud));
        if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x - 1, noeud->y, &noeud));
    }
    if (order == 3) {
        if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x - 1, noeud->y, &noeud));
        if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y - 1, &noeud));
        if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
            return (add_noeud(noeud->x, noeud->y + 1, &noeud));
        if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
            return (add_noeud(noeud->x + 1, noeud->y, &noeud));
    }
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
    if (ac == 4)
        imperfecte_maze(ac, av);
    map = perfecte_maze(ac, av);
    map = generate(map, &noeud, av);
    for (; map[a + 1]; a++)
        printf("%s\n", map[a]);
    printf("%s", map[a]);
    return (0);
}