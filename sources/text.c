/*
** EPITECH PROJECT, 2017
** MY_HUNTER
** File description:
** Text.c
*/

#include "../include/my.h"

void	init_list_text(list_text_t *list_text)
{
	list_text[0].timer_pos.x = 1735;
	list_text[0].timer_pos.y = 868;
	list_text[0].score_pos.x = 220;
	list_text[0].score_pos.y = 868;
	list_text[0].score = 0;
	list_text[0].timer = 30;
	list_text[0].font = sfFont_createFromFile("images/font.ttf");
	list_text[0].score_displayed = sfText_create();
	list_text[0].timer_displayed = sfText_create();
	list_text[0].score_str = malloc(sizeof(char) * 25600);
	list_text[0].timer_str = malloc(sizeof(char) * 25600);
	sfText_setFont(list_text[0].timer_displayed, list_text[0].font);
	sfText_setFont(list_text[0].score_displayed, list_text[0].font);
	sfText_setCharacterSize(list_text[0].score_displayed, 32);
	sfText_setCharacterSize(list_text[0].timer_displayed, 32);
	sfText_setPosition(list_text[0].score_displayed, list_text[0].score_pos);
	sfText_setPosition(list_text[0].timer_displayed, list_text[0].timer_pos);
	sfText_setColor(list_text[0].timer_displayed, sfCyan);
	sfText_setColor(list_text[0].score_displayed, sfCyan);
	my_getcharstar(list_text[0].score, list_text[0].score_str);
	my_getcharstar(list_text[0].timer, list_text[0].timer_str);
	sfText_setString(list_text[0].score_displayed, list_text[0].score_str);
	sfText_setString(list_text[0].timer_displayed, list_text[0].timer_str);
}

void 	display_text(list_text_t *list_text, sfRenderWindow *window)
{
	my_getcharstar(list_text[0].score, list_text[0].score_str);
	my_getcharstar(list_text[0].timer, list_text[0].timer_str);
	sfText_setString(list_text[0].score_displayed, list_text[0].score_str);
	sfText_setString(list_text[0].timer_displayed, list_text[0].timer_str);
	sfRenderWindow_drawText(window, list_text[0].score_displayed, NULL);
	sfRenderWindow_drawText(window, list_text[0].timer_displayed, NULL);
}