/*
** EPITECH PROJECT, 2025
** Current project
** File description:
** Tek1 project at Epitech
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    int r_value = check_returns(display_description(ac, av));
    list_t *table = NULL;

    if (r_value == 84)
        return 84;
    r_value = parse_file(av, &table);
    if (r_value == 84)
        return 84;
    init(table);
    free(table);
    return 0;
}
