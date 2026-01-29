/*
** EPITECH PROJECT, 2025
** dq
** File description:
** ddqqd
*/

#include "../include/my.h"
#include <sys/stat.h>

char *read_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat mystat;
    char *buffer = NULL;
    int ret0 = 0;
    int ret1 = 0;

    if (fd == -1)
        return NULL;
    ret0 = stat(av[1], &mystat);
    if (ret0 == -1)
        return NULL;
    buffer = malloc(sizeof(char) * mystat.st_size);
    ret1 = read(fd, buffer, mystat.st_size);
    if (ret1 == -1) {
        free(buffer);
        return NULL;
    }
    buffer[ret1 - 1] = '\0';
    close(fd);
    return buffer;
}

static int how_many_rows(char *buffer)
{
    int i = 0;

    for (int j = 0; buffer[j]; j++)
        if (buffer[j] == '\n')
            i++;
    i++;
    free(buffer);
    return i;
}

list_t *fill_table(char **av, list_t **table)
{
    char *buffer = read_file(av);
    int nb_rows = how_many_rows(buffer);

    *table = malloc(sizeof(list_t) * nb_rows + 1);
    (*table)[0].index = 0;
    (*table)[0].nb_rows = nb_rows;
    //(*table)[nb_rows].type = 'Z';
    return NULL;
}
//ayant trop compliqué mon code je stocke le nombre d'éléments uniquement au 1er index de mon tableau de struct
