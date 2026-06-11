##
## EPITECH PROJECT, 2025
## my_hunter
## File description:
## Makefile of ly_hunter
##

NAME = 	calc

CC =	epiclang

SRC =   ./lib/my/my_put_nbr.c \
		./lib/my/my_putstr.c \
		./lib/my/my_put_error.c \
		./lib/my/my_strlen.c \
		./lib/my/my_strlen_tab.c \
		./lib/my/my_strcmp.c \
		./lib/my/my_strncmp.c \
		./lib/my/my_putchar.c \
		./lib/my/my_strchr.c \
		./lib/my/my_strcpy.c \
		./lib/my/my_strdup.c \
		./lib/my/my_realloc.c \
		./lib/my/my_strcat.c \
		./lib/my/my_getnbr.c \
		./lib/my/my_atoi.c \
		./lib/my/my_str_to_word_array.c \
		./lib/my/my_revstr.c \
		./src/main.c \
		./src/eval_expr.c \
		./src/handle_parenthesis.c \
		./src/handle_addition.c \
		./src/handle_subtraction.c \
		./src/handle_signs.c \
		./src/handle_multiplication.c \
		./src/bistromatic.c


OBJ =	$(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra
TESTS_SRC = $(wildcard tests/*.c)
TESTS = $(TESTS_SRC:.c=.o)

FILTERING = $(filter-out ./src/main.o, $(OBJ))

all : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f $(TESTS)
	@find . -type f \( -name '*.gcda' -o -name '*.gcno' \) -delete

fclean : clean
	rm -f $(NAME)
	rm -f ./unit_tests

re : fclean all

tests_run : CFLAGS += --coverage
tests_run : $(FILTERING) $(TESTS)
	$(CC) -o ./unit_tests $(FILTERING) $(TESTS) $(CFLAGS) -lcriterion
	@./unit_tests