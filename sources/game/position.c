/*
** EPITECH PROJECT, 2017
** position.c
** File description
** position.c
*/

#include "my.h"

void	change_all_position(mob_t *list_mob, int size)
{
	int i = 0;
	for (i = 0; i < size ; i++) {
		list_mob[i].position.x += list_mob[i].move.x;
		list_mob[i].position.y += list_mob[i].move.y;
		sfSprite_setPosition(list_mob[i].sprite, list_mob[i].position);
	}
}

void	rebound(mob_t *list_mob, int size, sfIntRect rect)
{
	int i = 0;
	for (i = 0; i < size ; i++) {
		if (list_mob[i].position.x + 113 > 1828)
			list_mob[i].move.x *= -1;
		else if (list_mob[i].position.x < 74)
			list_mob[i].move.x *= -1;
		else if (list_mob[i].position.y + 87 > 851)
			list_mob[i].move.y *= -1;
		else if (list_mob[i].position.y < 74)
			list_mob[i].move.y *= -1;
	}
}