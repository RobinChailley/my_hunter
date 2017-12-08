/*
** EPITECH PROJECT, 2017
** init.c
** File description
** init.c
*/

#include "my.h"

void    init_other_sprite(other_sprite_t *list_other_sprite)
{
        list_other_sprite[0].texture = sfTexture_createFromFile("images/game/background_hud.png", NULL);
        list_other_sprite[0].sprite = sfSprite_create();
        sfSprite_setTexture(list_other_sprite[0].sprite, list_other_sprite[0].texture, sfTrue);
}

void    init_list_mob(mob_t *list_mob, sfIntRect rect)
{
        list_mob[0].position.x = 200;
        list_mob[0].position.y = 200;
        list_mob[0].move.x = 2;
        list_mob[0].move.y = 0;
        list_mob[0].sprite = sfSprite_create();
        list_mob[0].texture = sfTexture_createFromFile("images/game/spritesheet.png", NULL);
        sfSprite_setTexture(list_mob[0].sprite, list_mob[0].texture, sfTrue);
        sfSprite_setTextureRect(list_mob[0].sprite, rect);
        list_mob[0].killed = 0;
}