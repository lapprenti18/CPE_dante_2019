##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/main.c \
		src/check_valid_file.c \
		src/str_to_word_array.c

CC	= 	gcc -Wextra -W

OBJ = $(SRC:.c=.o)

NAME = solver

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all