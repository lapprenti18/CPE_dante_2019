/*
** EPITECH PROJECT, 2020
** add_node.c
** File description:
** add_node.c
*/

#include "../include/linked_list.h"

void add_node_at_front(int value, list_t **node)
{
    list_t *new = malloc(sizeof(list_t));

    new->value = value;
    new->previous = NULL;

    if (*node == NULL) {
        new->next = NULL;
        *node = new;
        return;
    }
    (*node)->previous = new;
    new->next = *node;
    *node = (*node)->previous;
}

void delete_node(list_t **node, list_t *pointer)
{
    if (*node == NULL || pointer == NULL)
        return;
    if (*node == pointer) {
        *node = pointer->next;
    }
    if (pointer->next != NULL) {
        pointer->next->previous = pointer->previous;
    }
    if (pointer->previous) {
        pointer->previous->next = pointer->next;
    }
    free(pointer);
}

void add_node_at_back(int value, list_t **node)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = *node;

    new->value = value;
    new->next = NULL;

    if (*node == NULL) {
        new->previous = NULL;
        *node = new;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->previous = tmp;
}