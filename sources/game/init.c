/*
** EPITECH PROJECT, 2017
** init.c
** File description
** init.c
*/

#include "my.h"

void	init_other_sprite(other_sprite_t *list_other_sprite)
{
	list_other_sprite[0].texture = sfTexture_createFromFile(
	"images/game/background_hud.png", NULL);
	list_other_sprite[0].sprite = sfSprite_create();
	sfSprite_setTexture(list_other_sprite[0].sprite,
	list_other_sprite[0].texture, sfTrue);
}

void	init_list_mob(mob_t *list_mob, sfIntRect rect)
{
	list_mob[0].position.x = 200;
	list_mob[0].position.y = 200;
	list_mob[0].move.x = 2;
	list_mob[0].move.y = 0;
	list_mob[0].sprite = sfSprite_create();
	list_mob[0].texture = sfTexture_createFromFile(
	"images/game/spritesheet.png", NULL);
	sfSprite_setTexture(list_mob[0].sprite, list_mob[0].texture, sfTrue);
	sfSprite_setTextureRect(list_mob[0].sprite, rect);
	list_mob[0].killed = 0;
}

void	init_all_list(list_text_t *list_text, mob_t *list_mob,
	sfIntRect rect, other_sprite_t *list_other_sprite)
{
	init_list_text(list_text);
	init_list_text2(list_text);
	init_list_mob(list_mob, rect);
	init_other_sprite(list_other_sprite);
}

void	init_score_text(score_end_t *score_end_txt, int score)
{
	score_end_txt[0].score_str_end = malloc(sizeof(char) * 10000);
	score_end_txt[0].text = sfText_create();
	score_end_txt[0].font = sfFont_createFromFile("images/font.ttf");
	score_end_txt[0].score_end = score;
	score_end_txt[0].score_end_pos.x = 966;
	score_end_txt[0].score_end_pos.y = 465;
	my_getcharstar(score_end_txt[0].score_end,
	score_end_txt[0].score_str_end);
	sfText_setColor(score_end_txt[0].text, sfWhite);
	sfText_setFont(score_end_txt[0].text, score_end_txt[0].font);
	sfText_setCharacterSize(score_end_txt[0].text, 32);
}