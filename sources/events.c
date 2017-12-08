/*
** EPITECH PROJECT, 2017
** animation.c
** File description
** animation.c
*/

#include "my.h"

void    gestion_event(sfRenderWindow *window, sfEvent event, mob_t *list_mob, int size, list_text_t *list_text)
{
        int i = 0;
        int compteur = 0;
        while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                        sfRenderWindow_close(window);
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

sfVector2f    get_mouse_position(sfRenderWindow *window)
{
        sfVector2i position_cursor;
        sfVector2f position_cursor_float;
        position_cursor = sfMouse_getPositionRenderWindow(window);
        position_cursor_float.x = position_cursor.x - 20;
        position_cursor_float.y = position_cursor.y -20;
        return (position_cursor_float);
}