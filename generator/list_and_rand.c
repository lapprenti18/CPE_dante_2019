/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "generator.h"

int randoz(int a)
{
    srand(time(NULL));
    return (rand() % a);
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
