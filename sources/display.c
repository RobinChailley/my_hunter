/*
** EPITECH PROJECT, 2017
** display.c
** File description
** display.c
*/

#include "my.h"

void    display_list_mob(mob_t *list_mob, int size, sfRenderWindow *window)
{
        int i = 0;
        for (i = 0; i < size; i++) {
                if (list_mob[i].killed == 0)
                        sfRenderWindow_drawSprite(window, list_mob[i].sprite, NULL);
        }

}

void    display_other_sprite(other_sprite_t * list_other_sprite, sfRenderWindow *window)
{
        sfRenderWindow_drawSprite(window, list_other_sprite[0].sprite, NULL);
}