/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/sysmacros.h>

typedef struct generator_s
{
    int y;
    int x;
    struct generator_s *next;
    struct generator_s *previous;
}generator_t;

void orde_one(generator_t *noeud, char **map);
void orde_two(generator_t *noeud, char **map);
void orde_tree(generator_t *noeud, char **map);
void orde_four(generator_t *noeud, char **map);
int check_neibors(char **map, generator_t *noeud);
int check_creusage(int x, int y, char **map, generator_t *noeud);
void creuse(char **map, generator_t *noeud, int check_x, int check_y);
void add_noeud(int x, int y, generator_t **noeud);
int randoz(int a);
