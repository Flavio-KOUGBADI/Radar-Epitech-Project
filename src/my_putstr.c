/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"
void my_putstr(char *str)
{
    if (str == NULL)
        return;
    while (*str) {
        write(2, str, 1);
        str++;
    }
}
