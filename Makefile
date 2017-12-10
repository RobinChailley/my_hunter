## /*
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
## */

CC		=	gcc -g

CFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I ./include

LDFLAGS		=	-lc_graph_prog

RM		=	rm -f

SRCS 		=	main.c	\
			sources/game/game.c	\
			sources/game/lib.c	\
			sources/game/animation.c 	\
			sources/game/display.c 	\
			sources/game/events.c 	\
			sources/game/init.c 	\
			sources/game/position.c 	\
			sources/window.c 	\
			sources/game/init2.c 	\
			sources/main_menu/main_menu.c 	\
			sources/end_menu/end_menu.c 	\

OBJS 		=	$(SRCS:.c=.o)

NAME 		=	my_hunter 	\

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
