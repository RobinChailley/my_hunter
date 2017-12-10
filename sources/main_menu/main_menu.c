/*
** EPITECH PROJECT, 2017
** MY_HUNTER
** File description:
** main_menu.c
*/

#include "my.h"

int	main_menu(sfRenderWindow *window)
{
	int main_menu = 1;
	sfSprite *main_menu_sprite = sfSprite_create();
	sfSprite *selection_sprite = sfSprite_create();
	sfTexture *selection_texture = sfTexture_createFromFile("images/selection_main_menu.png", NULL);
	sfTexture *main_menu_texture = sfTexture_createFromFile("images/main_menu.png", NULL);
	sfVector2f selection_position = {-400, -400};
	sfSprite_setTexture(main_menu_sprite, main_menu_texture, sfTrue);
	sfSprite_setTexture(selection_sprite, selection_texture, sfTrue);
	sfEvent event;
	sfSprite_setColor(selection_sprite, (sfColor){255, 255, 255, 125});
	sfRenderWindow_setMouseCursorVisible(window, 1);

	while (main_menu == 1) {
		gestion_event_mm(window, event, &main_menu, &selection_position);
		sfSprite_setPosition(selection_sprite, selection_position);
		sfRenderWindow_drawSprite(window, main_menu_sprite, NULL);
		sfRenderWindow_drawSprite(window, selection_sprite, NULL);
		sfRenderWindow_display(window);
		sfRenderWindow_clear(window, sfBlack);
	}
	return (main_menu);
}