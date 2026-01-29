/*
** EPITECH PROJECT, 2025
** Current project
** File description:
** Tek1 project at Epitech
*/

#include "../include/my.h"

int display_description(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("Air traffic simulation panel\n");
        my_putstr("USAGE\n");
        my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
        my_putstr("    path_to_script The path to the script file.\n");
        my_putstr("OPTIONS\n");
        my_putstr("  -h             print the usage and quit.\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr("  'L' key        enable/disable hitboxes and areas.\n");
        my_putstr("  'S' key        enable/disable sprites.\n");
    }
    if (ac == 1) {
        my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
        my_putstr("retry with -h");
        return 84;
    }
    if (ac > 2)
        return 84;
    return 0;
}
