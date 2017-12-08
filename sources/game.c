/*
** EPITECH PROJECT, 2017
** Main.c
** File description
** Main.c
*/


#include "../include/my.h"

void    add_mob(mob_t *list_mob, int *size, sfVector2i random_position, sfVector2i random_move, sfTexture *spritesheet_txtr)
{
        int i = *size;
        list_mob[i].position.x = random_position.x;
        list_mob[i].position.y = random_position.y;
        list_mob[i].move.x = random_move.x;
        list_mob[i].move.y = random_move.y;
        list_mob[i].sprite = sfSprite_create();
        list_mob[i].texture = spritesheet_txtr;
        sfSprite_setTexture(list_mob[i].sprite, list_mob[i].texture, sfTrue);
        sfSprite_setPosition(list_mob[i].sprite, list_mob[i].position);

        list_mob[i].killed = 0;
        *size += 1;
}

int     rand_a_b(int a, int b)
{
        return (rand()%(b-a) +a);
}

sfVector2i      rand_a_b_vector(sfVector2i vector, int a, int b, int a2, int b2)
{
        int x = rand()%(b-a) +a;
        int y = rand()%(b2-a2) +a2;
        vector.x = x;
        vector.y = y;
        return (vector);

}

void    position_treatment(mob_t *list_mob, int size, sfIntRect rect)
{
        reverse(list_mob, size);
        change_all_position(list_mob, size);
        put_all_rect(rect, list_mob, size);
        rebound(list_mob, size, rect);
}

void    display_all(sfRenderWindow *window, other_sprite_t *list_other_sprite, mob_t *list_mob, list_text_t *list_text,
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

int     game()
{
        sfTexture *spritesheet_txtr = sfTexture_createFromFile("images/game/spritesheet.png", NULL);
        int loop = 1;
        sfIntRect rect = {0, 0, 113, 87};
        
        mob_t *list_mob = malloc(sizeof(mob_t) * 10000000);
        list_text_t *list_text = malloc(sizeof(list_text_t) * 10000);
        other_sprite_t *list_other_sprite = malloc(sizeof(other_sprite_t) * 1000000);
        sfSprite *cursor_sprite = sfSprite_create();
        sfTexture *cursor_texture = sfTexture_createFromFile("images/game/cursor.png", NULL);
        sfSprite_setTexture(cursor_sprite, cursor_texture, sfTrue);
        init_list_text(list_text);
        init_list_mob(list_mob, rect);
        init_other_sprite(list_other_sprite);


        int size = 1;
        sfClock *clock;
        sfTime time;
        clock = sfClock_create();
        float seconds;
        sfVector2f position_cursor;
        sfRenderWindow *window = create_window();
        sfEvent event;
        sfRenderWindow_setMouseCursorVisible(window, 0);




        sfVector2i random_pos = {0, 0};
        sfVector2i random_move = {0, 0};
        while (sfRenderWindow_isOpen(window)) {
                time = sfClock_getElapsedTime(clock);
                seconds = time.microseconds / 1000000.0;
                gestion_event(window, event, list_mob, size, list_text);
                

                if (seconds > 1 ) {
                        random_pos = rand_a_b_vector(random_pos, 190, 1700, 190, 600);
                        random_move = rand_a_b_vector(random_move, -3, 3, -3, 3);
                        add_mob(list_mob, &size, random_pos, random_move, spritesheet_txtr);
                        list_text[0].timer -= 1;
                        sfClock_restart(clock);
                }
                

                if (seconds > 0.2) {
                        move_rect(&rect, 113, 452);
                }
                
                position_treatment(list_mob, size, rect);
                display_all(window, list_other_sprite, list_mob, list_text, position_cursor, cursor_sprite, size);
                
                if (list_text[0].timer < 0) {
                        free(list_mob);
                        free(list_other_sprite);
                        return (84);
                }
        }
}
