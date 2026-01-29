/*
** EPITECH PROJECT, 2025
** dld
** File description:
** dd
*/

#include "../include/my.h"

void free_something(char **array, char *line, FILE *stream)
{
    free_array(array);
    free(line);
    fclose(stream);
}

static void free_two(char *line, FILE *stream)
{
    free(line);
    fclose(stream);
}

int file_to_2d_array(char **av, list_t **table)
{
    char **array = NULL;
    FILE *stream = fopen(av[1], "r");
    size_t len = 0;
    char *line = NULL;

    if (stream == NULL) {
        my_putstr("\e[1;33mFile Opening failed.\n\tIs the file valide ?");
        return 84;
    }
    fill_table(av, table);
    while (getline(&line, &len, stream) != -1) {
        array = create_2d_array(line);
        treatment_center(table, array, line, stream);
        if (errno == -1)
            return 84;
        free_array(array);
    }
    free_two(line, stream);
    return 0;
}

int parse_file(char **av, list_t **table)
{
    int ret = file_to_2d_array(av, table);

    if (ret == 84)
        return 84;
    return 0;
}
