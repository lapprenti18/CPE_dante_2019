##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

all	:
	make -C solver
	make -C generator

clean	:
	make clean -C solver
	make clean -C generator

fclean	:
	make fclean -C solver
	make fclean -C generator

re	:
	make re -C solver
	make re -C generator