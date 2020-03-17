/*
** EPITECH PROJECT, 2020
** linked_list.h
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "main.h"

typedef struct list_s {
    int value;
    struct list_s *previous;
    struct list_s *next;
} list_t;



#endif /* !LINKED_LIST_H_ */
