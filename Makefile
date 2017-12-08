## /*
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
## */

CC		=	gcc -g

CFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I ./include

GRAPHFLAGS	=	-lc_graph_prog #-lcsfml-window -lcsfml-system -lcsfml-graphics

RM		=	rm -f

SRCS 		=	main.c	\
			sources/game.c	\
			sources/lib.c	\
			sources/animation.c 	\
			sources/display.c 	\
			sources/events.c 	\
			sources/init.c 	\
			sources/position.c 	\
			sources/window.c 	\
			sources/text.c 	\

OBJS 		=	$(SRCS:.c=.o)

NAME 		=	my_hunter 	\

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(GRAPHFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
