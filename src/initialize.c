/*
** EPITECH PROJECT, 2025
** zs
** File description:
** s
*/

#include "../include/my.h"

static void create_circleShape(list_t *table, recipe_t *all)
{
    for (int i = 0; i < table[0].nb_rows; i++) {
        if (table[i].type == 'T')
            table[i].circle = sfCircleShape_create();
        if (table[i].type == 'A')
            table[i].rect = sfRectangleShape_create();
        
    }
}

static void init_create(recipe_t *all, list_t *table)
{
    all->mode.width = 1920;
    all->mode.height = 1080;
    all->mode.bitsPerPixel = 32;
    all->window = sfRenderWindow_create(MODE, "My_radar",
        sfDefaultStyle, NULL);
    T_BG = sfTexture_createFromFile("assets/map.png", NULL);
    all->t_tower = sfTexture_createFromFile("assets/tower.png", NULL);
    S_BG = sfSprite_create();
    sfSprite_setTexture(S_BG, T_BG, sfTrue);
    sfSprite_setScale(S_BG, (sfVector2f){0.82, 0.8});
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    create_circleShape(table, all);
}

void init_event(recipe_t *all)
{
    while (sfRenderWindow_pollEvent(WINDOW, &all->event)) {
        if (all->event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEscape)
            sfRenderWindow_close(WINDOW);
    }
}

static void display_towers(list_t *table, recipe_t *all)
{
    for (int i = 0; i < table[0].nb_rows; i++) {
        if (table[i].type == 'T') {
            sfCircleShape_setTexture(table[i].circle, all->t_tower, sfTrue);
            sfCircleShape_setRadius(table[i].circle, table[i].radius);
            sfCircleShape_setScale(table[i].circle, (sfVector2f){0.125, 0.1251});
            sfCircleShape_setPosition(table[i].circle, table[i].start);
            sfCircleShape_setOutlineColor(table[i].circle, sfCyan);
            sfCircleShape_setOutlineThickness(table[i].circle, 4);
            sfRenderWindow_drawCircleShape(all->window, table[i].circle, NULL);
        }
    }
}

void init_play(recipe_t *all, list_t *table)
{
    init_create(all, table);
    while (sfRenderWindow_isOpen(WINDOW)) {
        init_event(all);
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfRenderWindow_drawSprite(WINDOW, S_BG, NULL);
        display_towers(table, all);
        sfRenderWindow_display(WINDOW);
    }
}

/*TEXTURE is the bg texture and SPRITE is BG sprite*/
void init_destroy(recipe_t *all, list_t *table)
{
    for (int i = 0; i < table[0].nb_rows; i++) {
        if (table[i].type == 'T')
            sfCircleShape_destroy(table[i].circle);
        if (table[i].type == 'A')
            sfRectangleShape_destroy(table[i].rect);
    }
    sfTexture_destroy(all->t_tower);
    sfTexture_destroy(T_BG);
    sfSprite_destroy(S_BG);
    sfRenderWindow_destroy(WINDOW);
    free(all);
}

void init(list_t *table)
{
    recipe_t *all = malloc(sizeof(recipe_t));

    init_play(all, table);
    init_destroy(all, table);
}
