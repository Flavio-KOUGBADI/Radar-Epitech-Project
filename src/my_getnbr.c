/*
** EPITECH PROJECT, 2025
** kds
** File description:
** dk
*/

#include "../include/my.h"

double my_atof(const char *str)
{
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }
    for (; *str >= '0' && *str <= '9'; str++)
        result = result * 10 + (*str - '0');
    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            fraction /= 10;
            result += (*str - '0') * fraction;
            str++;
        }
    }
    return result * sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    double nb = 0;
    int l = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < '-' || str[i] > '9'))
            return -1;
        nb = my_atof(str);
    }
    return nb;
}
