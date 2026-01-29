/*
** EPITECH PROJECT, 2025
** ss
** File description:
** rf
*/

#include "../include/my.h"

static void checker_a(char **array, char *line, FILE *stream)
{
    if (my_strcmp(array[0], "A") && my_strcmp(array[0], "T")) {
        my_putstr("\x1b[38;5;151mBad file[0m");
        free_three(array, line, stream);
        errno = -1;
        return;
    }
}

static void checker_b(char **array, char *line, FILE *stream)
{
    int nb_rows = 0;

    for (; array[nb_rows] != NULL; nb_rows++);
    if (my_strcmp(array[0], "A") == 0 && nb_rows != 7) {
        my_putstr("\x1b[38;5;151mInvalid file[0m");
        free_three(array, line, stream);
        errno = -1;
        return;
    }
    if (my_strcmp(array[0], "T") == 0 && nb_rows != 4) {
        my_putstr("\x1b[38;5;151mInvalid File[0m");
        free_three(array, line, stream);
        errno = -1;
        return;
    }
}

void free_three(char **array, char *line, FILE *stream)
{
    free_array(array);
    free(line);
    fclose(stream);
}

static void checker_c(char **array, char *line, FILE *stream)
{
    int i = 1;
    double mean = 0.5 * (my_getnbr(array[1]) + my_getnbr(array[3]));

    for (; my_strcmp(array[0], "A") == 0 && array[i]; i++) {
        if (mean < 0 || mean > 1920) {
            my_putstr("\x1b[38;5;151mInvalid Number for x[0m");
            errno = -1;
            free_three(array, line, stream);
            return;
        }
        mean = 0.5 * ((my_getnbr(array[2]) + my_getnbr(array[4])));
        if (mean < 0 || mean > 1080) {
            free_three(array, line, stream);
            errno = -1;
            return;
        }
    }
}

static void checker_d(char **array, char *line, FILE *stream)
{
    int i = 1;

    for (; my_strcmp(array[0], "T") == 0 && array[i]; i++) {
        if (my_getnbr(array[1]) < 0 || my_getnbr(array[1]) > 1920) {
            free_three(array, line, stream);
            errno = -1;
            return;
        }
        if (my_getnbr(array[2]) < 0 || my_getnbr(array[2]) > 1080) {
            free_three(array, line, stream);
            errno = -1;
            return;
        }
        if (my_getnbr(array[3]) < 0 || my_getnbr(array[3]) > 100) {
            free_three(array, line, stream);
            errno = -1;
            return;
        }
    }
}

static void checker_e(char **array, char *line, FILE *stream)
{
    int i = 1;

    for (; my_strcmp(array[0], "T") == 0 && array[i]; i++) {
        if (my_getnbr(array[i]) == -1) {
            free_three(array, line, stream);
            errno = -1;
            return;
        }
    }
    for (; my_strcmp(array[0], "A") == 0 && array[i]; i++) {
        if (my_getnbr(array[5]) < 0 || my_getnbr(array[6]) < 0) {
            my_putstr("\x1b[38;5;151mInvalid Number[0m");
            free_three(array, line, stream);
            errno = -1;
            return;
        }
    }
}

static void checker_f(char **array, char *line, FILE *stream)
{
    int i = 1;

    for (; my_strcmp(array[0], "A") == 0 && array[i]; i++) {
        if (my_getnbr(array[i]) == -1) {
            my_putstr("\x1b[38;5;151mGet number failed[0m");
            free_three(array, line, stream);
            errno = -1;
            return;
        }
    }
}

void fill_for_airplane(list_t *table, char **array, int tail)
{
    sfVector2f vector = {my_getnbr(array[1]), my_getnbr(array[2])};

    (table)[tail].type = 'A';
    (table)[tail].start = vector;
    vector.x = my_getnbr(array[3]);
    vector.y = my_getnbr(array[4]);
    (table)[tail].end = vector;
    (table)[tail].speed = my_getnbr(array[5]);
    (table)[tail].delay = my_getnbr(array[6]);
    POSITION.x = my_getnbr(array[3]) - my_getnbr(array[1]);
    POSITION.y = my_getnbr(array[4]) - my_getnbr(array[2]);
    table[tail].length = sqrt(pow(POSITION.x, 2) + pow(POSITION.y, 2));
    N_VECTOR.x = POSITION.x / LENGTH;
    N_VECTOR.y = POSITION.y / LENGTH;
}

void fill_for_tower(list_t *table, char **array, int tail)
{
    sfVector2f vector = {my_getnbr(array[1]), my_getnbr(array[2])};

    (table)[tail].type = 'T';
    (table)[tail].start = vector;
    (table)[tail].radius = (my_getnbr(array[3]) * 1920) / 100;
}

int treatment_center(list_t **table, char **array, char *line, FILE *stream)
{
    int index = (*table[0]).index;

    checker_a(array, line, stream);
    if (errno == -1)
        return 84;
    checker_b(array, line, stream);
    checker_c(array, line, stream);
    if (errno == -1)
        return 84;
    checker_d(array, line, stream);
    checker_e(array, line, stream);
    checker_f(array, line, stream);
    if (errno == -1)
        return 84;
    if (my_strcmp(array[0], "A") == 0)
        fill_for_airplane(*table, array, index);
    if (my_strcmp(array[0], "T") == 0)
        fill_for_tower(*table, array, index);
    (*table)[0].index++;
    return 0;
}
