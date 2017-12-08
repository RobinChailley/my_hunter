/*
** EPITECH PROJECT, 2017
** my.h
** File description
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

typedef struct mob_s
{
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f position;
        sfVector2f move;
        int killed;
}       mob_t;

typedef struct other_sprite_s
{
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f position;
}       other_sprite_t;

typedef struct 	list_text_s
{
	int score;
	int timer;
	char *score_str;
	char *timer_str;
	sfFont *font;
        sfText *score_displayed;
        sfText *timer_displayed;
        sfVector2f score_pos;
        sfVector2f timer_pos;
}	list_text_t;


sfRenderWindow 	*create_window();
void    	add_mob(mob_t *list_mob, int *size, sfVector2i random_position, sfVector2i random_move, sfTexture *spritesheet_txtr);
void    	init_list_mob(mob_t *list_mob, sfIntRect rect);
void    	display_list_mob(mob_t *list_mob, int size, sfRenderWindow *window);
void    	put_all_rect(sfIntRect rect, mob_t *list_mob, int size);
void    	move_rect(sfIntRect *rect, int offset, int max_value);
void    	gestion_event(sfRenderWindow *window, sfEvent event, mob_t *list_mobs, int size, list_text_t *list_text);
void    	change_all_position(mob_t *list_mob, int size);
void    	touched(mob_t *list_mob, int x, int y, int size);
int     	my_getnbr(char const *str);
sfVector2i      rand_a_b_vector(sfVector2i vector, int a, int b, int a2, int b2);
int 		game();
int     	rand_a_b(int a, int b);
void    	reverse(mob_t *list_mob, int size);
void    	display_other_sprite(other_sprite_t * list_other_sprite, sfRenderWindow *window);
sfVector2f    	get_mouse_position(sfRenderWindow *window);
void    	init_other_sprite(other_sprite_t *list_other_sprite);
void    	rebound(mob_t *list_mob, int size, sfIntRect rect);
void 		my_getcharstar(int nb, char *str);
void 		reverse_str(char *str);
void		init_list_text(list_text_t *list_text);
void 		display_text(list_text_t *list_text, sfRenderWindow *window);
void            position_treatment(mob_t *list_mob, int size, sfIntRect rect);
void            display_all(sfRenderWindow *window, other_sprite_t *list_other_sprite, mob_t *list_mob, list_text_t *list_text,
                sfVector2f position_cursor, sfSprite *cursor_sprite, int size);

#endif /* MY_H_ */
