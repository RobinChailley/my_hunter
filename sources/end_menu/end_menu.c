/*
** EPITECH PROJECT, 2017
** MY_HUNTER
** File description:
** end_menu.c
*/

#include "my.h"

int	end_menu(int score, sfRenderWindow *window)
{
	sfEvent event;
	sfRenderWindow_setMouseCursorVisible(window, 1);
	int return_value = 0;
	sfTexture *texture;
	texture = sfTexture_createFromFile("images/end_menu.png", NULL);
	sfSprite *end_menu_sprite = sfSprite_create();
	sfSprite_setTexture(end_menu_sprite, texture, sfTrue);
	int loop = 1;
	score_end_t *score_end_txt = malloc(sizeof(score_end_t));

	init_score_text(score_end_txt, score);
	while (loop) {
		event_gestion_me(window, event, &loop, &return_value);
		sfRenderWindow_drawSprite(window, end_menu_sprite, NULL);
		display_score_end(window, score_end_txt);
		sfRenderWindow_display(window);
		sfRenderWindow_clear(window, sfBlack);
	}
	free(score_end_txt);
	return (return_value);
}