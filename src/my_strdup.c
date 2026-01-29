/*
** EPITECH PROJECT, 2025
** kcf
** File description:
** ddd
*/

#include "../include/my.h"

char *my_strcpy1(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char *src)
{
    char *dest = NULL;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    my_strcpy1(dest, src);
    return dest;
}
