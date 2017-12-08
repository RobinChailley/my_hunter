/*
** EPITECH PROJECT, 2017
** animation.c
** File description
** animation.c
*/

#include "my.h"

void    move_rect(sfIntRect *rect, int offset, int max_value)
{
               if (rect->left != max_value)
                rect->left += offset;
               if (rect->left == max_value)
                       rect->left = 0;
}

void    put_all_rect(sfIntRect rect, mob_t *list_mob, int size)
{
        int i = 0;
        for (i = 0; i < size; i++)
                sfSprite_setTextureRect(list_mob[i].sprite, rect);
}

void    reverse(mob_t *list_mob, int size)
{
        sfTexture *reverse_texture;
        sfTexture *mob_texture;
        mob_texture = sfTexture_createFromFile("images/game/spritesheet.png", NULL);
        reverse_texture = sfTexture_createFromFile("images/game/spritesheet_reverse.png", NULL);
        int i = 0;
        for (i = 0; i < size ; i++) {
                if (list_mob[i].move.x < 0 )
                        sfSprite_setTexture(list_mob[i].sprite, reverse_texture, sfTrue);
                else
                        sfSprite_setTexture(list_mob[i].sprite, mob_texture, sfTrue);
        }
}
