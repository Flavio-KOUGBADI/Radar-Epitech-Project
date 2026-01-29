/*
** EPITECH PROJECT, 2025
** project
** File description:
** PSU
*/


#include "../include/my.h"

int check_returns(int r_value)
{
    if (r_value == 84 || r_value < 0)
        return 84;
    return 0;
}

int my_strcmp(char *first, char *second)
{
    int t = 0;

    if (my_strlen(first) != my_strlen(second))
        return 84;
    for (int i = 0; first[i] != '\0'; i++) {
        if (first[i] == second[i]);
        else
            return 84;
    }
    return t;
}
