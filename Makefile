# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 16:21:34 by manujime          #+#    #+#              #
#    Updated: 2023/05/01 14:31:16 by manujime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

SRC =   main.c \
		error_handling.c \
		time.c \
		utils.c \
		clean_up.c \
		philo_routine.c \
		existence.c \
			
OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)All clear"

re: fclean all

.PHONY: all clean fclean re bonus
