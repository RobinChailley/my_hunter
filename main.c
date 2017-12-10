/*
** EPITECH PROJECT, 2017
** MY_HUNTER
** File description:
** main.c
*/

#include "my.h"

int main()
{
	sfRenderWindow *window = create_window();
	int ret_main_menu;
	int ret_end_menu;
	int score = 20;
	int loop = 1;
	ret_main_menu = main_menu(window);
	while (loop) {
		if (ret_main_menu == 20 || ret_main_menu == -20)
			break;
		else if (ret_main_menu == 10)
			score = game(window);
		if (score == -20 )
			break;
		ret_end_menu = end_menu(score, window);
		if (ret_end_menu == 20 || ret_end_menu == -20)
			break;
	}
	sfRenderWindow_close(window);
	return (0);
}
