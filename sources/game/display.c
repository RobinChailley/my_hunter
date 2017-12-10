/*
** EPITECH PROJECT, 2017
** display.c
** File description
** display.c
*/

#include "my.h"

void	display_list_mob(mob_t *list_mob, int size, sfRenderWindow *window)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		if (list_mob[i].killed == 0)
			sfRenderWindow_drawSprite(window, list_mob[i].sprite
			, NULL);
	}

}

void	display_other_sprite(other_sprite_t * list_other_sprite,
	sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, list_other_sprite[0].sprite, NULL);
}

void	display_score_end(sfRenderWindow *window, score_end_t *score_end_txt)
{
	sfText_setString(score_end_txt[0].text,
	score_end_txt[0].score_str_end);
	sfText_setPosition(score_end_txt[0].text,
	score_end_txt[0].score_end_pos);
	sfRenderWindow_drawText(window, score_end_txt[0].text, NULL);
}

void	display_text(list_text_t *list_text, sfRenderWindow *window)
{
	my_getcharstar(list_text[0].score, list_text[0].score_str);
	my_getcharstar(list_text[0].timer, list_text[0].timer_str);
	sfText_setString(list_text[0].score_displayed, list_text[0].score_str);
	sfText_setString(list_text[0].timer_displayed, list_text[0].timer_str);
	sfRenderWindow_drawText(window, list_text[0].score_displayed, NULL);
	sfRenderWindow_drawText(window, list_text[0].timer_displayed, NULL);
}

void	display_all(sfRenderWindow *window, other_sprite_t *list_other_sprite,
	mob_t *list_mob, list_text_t *list_text,
	sfVector2f position_cursor, sfSprite *cursor_sprite, int size)
{
	display_other_sprite(list_other_sprite, window);
	display_list_mob(list_mob, size, window);
	display_text(list_text, window);

	position_cursor = get_mouse_position(window);
	sfSprite_setPosition(cursor_sprite, position_cursor);
	sfRenderWindow_drawSprite(window, cursor_sprite, NULL);
	sfRenderWindow_display(window);
	sfRenderWindow_clear(window, sfWhite);
}