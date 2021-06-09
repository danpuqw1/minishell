# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteemo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 21:04:34 by student           #+#    #+#              #
#    Updated: 2020/08/14 21:04:43 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
SRC			= src/main.c \
			  src/cmd_cd.c \
			  src/cmd_echo.c \
			  src/cmd_setenv.c \
			  src/cmds.c \
			  src/execute.c \
			  src/minishell.c \
			  src/utils/ft_bzero.c \
			  src/utils/ft_error.c \
			  src/utils/ft_find_env.c \
			  src/utils/ft_memalloc.c \
			  src/utils/ft_memset.c \
			  src/utils/ft_putchar.c \
			  src/utils/ft_putendl.c \
			  src/utils/ft_putstr.c \
			  src/utils/ft_strcat.c \
			  src/utils/ft_strchr.c \
			  src/utils/ft_strclr.c \
			  src/utils/ft_strcmp.c \
			  src/utils/ft_strcpy.c \
			  src/utils/ft_strdup.c \
			  src/utils/ft_strjoin.c \
			  src/utils/ft_strlen.c \
			  src/utils/ft_strncat.c \
			  src/utils/ft_strncmp.c \
			  src/utils/ft_strncpy.c \
			  src/utils/ft_strnew.c \
			  src/utils/ft_strrchr.c \
			  src/utils/ft_strsub.c \
			  src/utils/ft_strtok.c \
			  src/utils/ft_tabfree.c \
			  src/utils/ft_tablen.c \
			  src/utils/get_next_line.c
INC			= includes/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INC)
OBJ			= $(SRC:.c=.o)
DEBUG		= -g3 -fsanitize=address

all: $(NAME)
%.o: %.c
	@printf "[minishell] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[minishell] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[minishell] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
debug: $(OBJ)
	@printf "[minishell] Compiled debug successfuly! [OK]\n"
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@printf "[minishell] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[minishell] Removed minishell binary!\n"
re: fclean all

.PHONY: all clean fclean re
