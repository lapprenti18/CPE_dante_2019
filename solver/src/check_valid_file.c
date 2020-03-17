/*
** EPITECH PROJECT, 2020
** check_valid_file.c
** File description:
** check_valid_file.c
*/

#include "../include/main.h"

int check_valid_file2(char *buffer)
{
    if (buffer[0] != '*' || buffer[strlen(buffer) - 1] != '*') {
        printf("Please enter a valid map !\n");
        return (84);
    }
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n') {
            return (84);
        }
    }
    return (0);
}

int check_valid_file(char *filepath)
{
    int fd = 0;
    struct stat st;
    char *buffer = NULL;
    int size = 0;
    fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        printf("You must enter a valid file\n");
        return (84);
    }
    stat(filepath, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    size = read(fd, buffer, st.st_size + 1);
    buffer[size] = 0;

    if (check_valid_file2(buffer) == 84) {
        free(buffer);
        return (84);
    }
    free(buffer);
    return (0);
}