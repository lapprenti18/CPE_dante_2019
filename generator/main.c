/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

char **perfecte_maze(int height, int width)
{
    char **map = malloc(sizeof(char *) * (width + 1));

    map[width] = NULL;
    for (int a = 0; a < width; a++) {
        map[a] = malloc(sizeof(char) * (height + 1));
        map[a][height] = '\0';
        for (int b = 0; b < (height) ; b++) {
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

char **generate(char **map, generator_t *noeud, int check_y, int check_x)
{
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
    int height = atoi(av[1]);
    int width = atoi(av[2]);

    srand(time(NULL));
    noeud.x = 0;
    noeud.y = 0;
    noeud.next = NULL;
    noeud.previous = NULL;
    if (ac > 4 || ac < 3 || height <= 0 || width <= 0)
        return (84);
    do {
        map = perfecte_maze(height, width);
        map = generate(map, &noeud, height, width);
        if (ac == 3)
            map = imperfecte_maze(map);
    } while(map[width - 1][height - 1] == 'X');
    for (; map[a + 1]; a++)
        printf("%s\n", map[a]);
    printf("%s", map[a]);
    return (0);
}