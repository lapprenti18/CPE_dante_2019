/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

void creuse(char **map, generator_t *noeud, int check_x, int check_y)
{
    int order = rand() % 4;

    if (noeud->x == check_x - 2 && noeud->y == check_y - 1 && map[check_y - 1]\
    [check_x - 1] == 'X')
        return (add_noeud(check_x - 1, check_y - 1, &noeud));
    else if (noeud->x == check_x - 1 && noeud->y == check_y - 2 && map\
    [check_y - 1][check_x - 1] == 'X')
        return (add_noeud(check_x - 1, check_y - 1, &noeud));
    if (order == 0)
        orde_one(noeud, map);
    if (order == 1)
        orde_two(noeud, map);
    if (order == 2)
        orde_tree(noeud, map);
    if (order == 3)
        orde_tree(noeud, map);
}

void orde_one(generator_t *noeud, char **map)
{
    if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x + 1, noeud->y, &noeud));
    if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x - 1, noeud->y, &noeud));
    if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y - 1, &noeud));
    if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y + 1, &noeud));
}

void orde_two(generator_t *noeud, char **map)
{
    if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y + 1, &noeud));
    if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x + 1, noeud->y, &noeud));
    if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x - 1, noeud->y, &noeud));
    if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y - 1, &noeud));
}

void orde_tree(generator_t *noeud, char **map)
{
    if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y - 1, &noeud));
    if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y + 1, &noeud));
    if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x + 1, noeud->y, &noeud));
    if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x - 1, noeud->y, &noeud));
}

void orde_four(generator_t *noeud, char **map)
{
    if (check_creusage(noeud->x - 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x - 1, noeud->y, &noeud));
    if (check_creusage(noeud->x, noeud->y - 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y - 1, &noeud));
    if (check_creusage(noeud->x, noeud->y + 1, map, noeud) != 0)
        return (add_noeud(noeud->x, noeud->y + 1, &noeud));
    if (check_creusage(noeud->x + 1, noeud->y, map, noeud) != 0)
        return (add_noeud(noeud->x + 1, noeud->y, &noeud));
}