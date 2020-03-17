/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

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
    if (!(noeud->y == y + 1 && noeud->x == x) && map[y + 1] && map[y + 1]\
    [x] == '*')
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