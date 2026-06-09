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
		./lib/my/my_strcat.c \
		./lib/my/my_getnbr.c \
		./lib/my/my_atoi.c \
		./lib/my/my_revstr.c \
		./src/main.c \
		./src/eval_expr.c \
		./src/handle_parenthesis.c \


OBJ =	$(SRC:.c=.o)

CFLAGS = -I./include

all : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	rm -f $(OBJ)
	rm -f *~

fclean : clean
	rm -f $(NAME)

re : fclean all
