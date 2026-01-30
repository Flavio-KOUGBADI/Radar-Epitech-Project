/*
** EPITECH PROJECT, 2025
** Current project
** File description:
** Tek1 project at Epitech
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <errno.h>
    #define LENGTH table[tail].length
    #define P_WIDTH table[i].start.x
    #define P_HEIGHT table[i].start.y
    #define WINDOW all->window
    #define EVENT all->event
    #define S_BG all->s_bg
    #define S_PLANE all->s_plane
    #define T_BG all->t_bg
    #define T_PLANE all->t_plane
    #define T_TOWER all->t_tower
    #define MODE all->mode
    #define POSITION table[tail].position
    #define DX table[i].position.x
    #define DY table[i].position.y
    #define DY table[i].position.y
    #define N_VECTOR table[tail].normalized_vector
    #define VX table[i].normalized_vector.x
    #define VY table[i].normalized_vector.y
typedef struct list {
    sfSprite *sp;
    sfCircleShape *circle;
    char type;
    sfVector2f start;
    sfVector2f end;
    float speed;
    float delay;
    sfVector2f position;
    double radius;
    int index;
    double length;
    sfVector2f normalized_vector;
    sfVector2f offset;
    int nb_rows;
    int active;
} list_t;

typedef struct recipe {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfTexture *t_bg;
    sfSprite *s_bg;
    sfTexture *t_plane;
    sfTexture *t_tower;
} recipe_t;

int check_returns(int r_value);
int my_strcmp(char *first, char *second);
void my_putstr(char *str);
int second_main(int ac, char **av);
int parse_file(char **av, list_t **head);
int file_to_2d_array(char **av, list_t **head);
int my_strlen(char const *str);
char **load_array(char *line);
char **create_2d_array(char *line);
void add_to_end(list_t **head, list_t *node);
void free_array(char **array);
int my_getnbr(char const *str);
int check_array(char **array);
list_t *fill_table(char **av, list_t **table);
void free_three(char **array, char *line, FILE *stream);
void create_node(list_t **head, char **array);
int treatment_center(list_t **table, char **array, char *line, FILE *stream);
void init(list_t *table);
void fill_for_airplane(list_t *table, char **array, int tail);
void fill_for_tower(list_t *table, char **array, int tail);
int display_description(int ac, char **av);
char *my_strdup(char *src);
#endif
