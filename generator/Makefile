##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	main.c	\
		order.c	\
		neibors.c	\
		list_and_rand.c

NAME	=	generator

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	gcc -o $(NAME) $(SRC) -Ofast -O3 -g3

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
