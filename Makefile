##
## EPITECH PROJECT, 2025
## d
## File description:
## d
##


CC = clang

SRC =   src/main.c	\
	src/display_description.c	\
	src/my_putstr.c	\
	src/treatment.c	\
	src/create_2D_array.c	\
	src/my_strcmp.c	\
	src/fill_table.c	\
	src/my_getnbr.c	\
	src/initialize.c	\
	src/parse_file.c	\

NAME = my_radar

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -lm -g3

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re: clean fclean all

execute: re
	./$(NAME)
debugging: all
	valgrind --leak-check=full --show-leak-kinds=all ./my_radar 100_planes_8_towers.rdr
