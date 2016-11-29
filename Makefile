# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvillat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:31:10 by gvillat           #+#    #+#              #
#    Updated: 2016/06/06 16:56:24 by gvillat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = ft_ls

SRC_PATH = ./sources
OBJ_PATH = ./obj

SRC_NAME =	ft_ls.c\
			ft_l.c\
			ft_sort.c\
			ft_memory.c\
			ft_read.c\
			ft_opt.c\
			ft_display_time.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@cd ./lib/libft && $(MAKE) 
	@cd ./lib/libftprintf  && $(MAKE)
	@$(CC) $(FLAGS) -o $@ $^ ./lib/libft/libft.a ./lib/libftprintf/libftprintf.a
	@echo "\033[1;34mft_ls\t\t\033[1;33mCompilation\t\033[0;32m-OK-\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;34mft_ls\t\033[1;33mCleaning obj\t\033[0;32m-OK-\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@rm -rf ./lib/libft/libft.a ./lib/libftprintf/libftprintf.a
	@echo "\033[1;34mft_ls\t\033[1;33mCleaning lib\t\033[0;32m-OK-\033[0m"
	# @cd ./libft && $(MAKE) fclean

re: fclean all