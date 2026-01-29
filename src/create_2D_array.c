/*
** EPITECH PROJECT, 2025
** sds
** File description:
** z
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char **load_array(char *line)
{
    int j = 0;
    int nb_rows = 0;
    char **array = NULL;

    for (int i = 0; line[i] && line[i] != '\n'; i++)
        if (line[i] == ' ')
            nb_rows++;
    nb_rows++;
    array = malloc(sizeof(char *) * (nb_rows + 1));
    for (; j < nb_rows; j++)
        array[j] = malloc(sizeof(char) * (my_strlen(line)));
    return array;
}

char **create_2d_array(char *line)
{
    char **array = load_array(line);
    int i = 0;
    int j = 0;
    int k = 0;

    for (; line[k] && line[k] != '\n'; k++) {
        if (line[k] == ' ' || line[k] == '\t') {
            array[i][j] = '\0';
            i++;
            j = 0;
            k++;
        }
        array[i][j] = line[k];
        j++;
    }
    array[i][j] = '\0';
    array[i + 1] = NULL;
    return array;
}

/*creation of a function which verify if the file is
correct and call an otther function to fill the
 linked list with tha data obtained by the parsing*/
void free_array(char **array)
{
    int nb_rows = 0;

    for (; array[nb_rows] != NULL; nb_rows++);
    nb_rows++;
    for (int j = 0; j < nb_rows; j++)
        free(array[j]);
    free(array);
}
