##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	

NAME	=	mysh

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	cd generator ; make re ;cd ../solver ; make re ;

clean	:
	cd generator ; make clean ;cd ../solver ; make clean ;

fclean	:
	cd generator ; make fclean ;cd ../solver ; make fclean ;

re	:
	cd generator ; make fclean ;cd ../solver ; make fclean ;
