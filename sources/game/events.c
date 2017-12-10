/*
** EPITECH PROJECT, 2017
** animation.c
** File description
** animation.c
*/

#include "my.h"

void	gestion_event(sfRenderWindow *window, sfEvent event, mob_t *list_mob,
	int size, list_text_t *list_text)
{
	int i = 0;
	int compteur = 0;
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window);
			list_text->score = -20;

		}
		if (event.type == sfEvtMouseButtonPressed) {
			for (i = 0 ; i < size ; i++) {
				if (event.mouseButton.x > list_mob[i].position.x  && event.mouseButton.x < list_mob[i].position.x + 113
				&& event.mouseButton.y > list_mob[i].position.y && event.mouseButton.y < list_mob[i].position.y + 87) {
				list_mob[i].killed = 1;
					if (compteur == 0) {
						list_text->score += 1;
						compteur++;
					}
				}
			}
		}
	}
}

sfVector2f	get_mouse_position(sfRenderWindow *window)
{
	sfVector2i position_cursor;
	sfVector2f position_cursor_float;
	position_cursor = sfMouse_getPositionRenderWindow(window);
	position_cursor_float.x = position_cursor.x - 20;
	position_cursor_float.y = position_cursor.y -20;
	return (position_cursor_float);
}

void	event_gestion_me(sfRenderWindow *window, sfEvent event,
	int *loop, int *return_value)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			if (event.mouseButton.x > 614
			&& event.mouseButton.x < 763
			&& event.mouseButton.y > 611
			&& event.mouseButton.y < 643) {
				*loop = 0;
				*return_value = 10;
			}
			if (event.mouseButton.x > 1193  &&
			event.mouseButton.x < 1295 &&
			event.mouseButton.y > 621 &&
			event.mouseButton.y < 653) {
				*loop = 0;
				*return_value = 20;
			}
		}
	}
}

void	gestion_event_mm(sfRenderWindow *window, sfEvent event,
	int *main_menu, sfVector2f *selection_position)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseButtonPressed) {
			if (event.mouseButton.x > 639  && event.mouseButton.x < 1268 &&
			event.mouseButton.y > 219 && event.mouseButton.y < 439)
				*main_menu = 10;
			if (event.mouseButton.x > 653  && event.mouseButton.x < 1273 &&
			event.mouseButton.y > 560 && event.mouseButton.y < 784)
				*main_menu = 20;
		}
		sfVector2f position_cursor = get_mouse_position_mm(window);
		if (position_cursor.x > 639  && position_cursor.x < 1268 &&
		position_cursor.y > 219 && position_cursor.y < 439) {
			selection_position->x = 639;
			selection_position->y = 219;
		} else if (position_cursor.x > 653  && position_cursor.x < 1273 &&
		position_cursor.y > 560 && position_cursor.y < 784) {
			selection_position->x = 653;
			selection_position->y = 561;
		}
	}
}

sfVector2f	get_mouse_position_mm(sfRenderWindow *window)
{
	sfVector2i position_cursor;
	sfVector2f position_cursor_float;
	position_cursor = sfMouse_getPositionRenderWindow(window);
	position_cursor_float.x = position_cursor.x;
	position_cursor_float.y = position_cursor.y;
	return (position_cursor_float);
}