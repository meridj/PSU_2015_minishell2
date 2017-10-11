##
## Makefile for minishell2 in /home/meridj/Rendu/minishell1/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Sun Apr 10 15:24:10 2016 John Doe
## Last update Tue Apr 12 20:06:45 2016 Mehdi
##

NAME	= mysh

CFLAGS	= -Wall -Wextra -W -I./inc/

LIB     = -L./lib/ -lmy

SRC	= srcs/main.c \
	  srcs/builtins.c \
	  srcs/free.c \
	  srcs/copy_env.c \
	  srcs/exit.c \
	  srcs/fork.c \
	  srcs/path.c \
	  srcs/cd.c \
	  srcs/cd_2.c \
	  srcs/print.c \
	  srcs/print_2.c \
	  srcs/check_command.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
