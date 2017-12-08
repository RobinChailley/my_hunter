/*
** EPITECH PROJECT, 2017
** window.c
** File description
** window.c
*/

#include "my.h"

sfRenderWindow         *create_window()
{
        sfRenderWindow *window;
        sfVideoMode mode = {1920, 1000, 32};
        window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
        return (window);
}
