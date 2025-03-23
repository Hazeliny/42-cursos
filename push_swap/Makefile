# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 12:04:36 by linyao            #+#    #+#              #
#    Updated: 2025/03/23 20:16:28 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC = complex_sort.c init_stack.c operation_rev_rotate.c \
		config_node_a.c operation_rotate.c simple_sort.c \
      	config_node_b.c operation_swap.c swap_split.c \
      	handle_errors.c operation_push.c push_swap.c \
		utils_stack.c utils_sort.c

SRC_BONUS = bonus/checker.c bonus/init_stack.c bonus/operations.c \
		bonus/swap_split.c bonus/utils_stack.c bonus/operation_swap.c \
		bonus/operation_push.c bonus/operation_rotate.c \
		bonus/operation_rev_rotate.c bonus/handle_errors.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = ${SRC_BONUS:.c=.o}
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = libft/libft.h libft/get_next_line.h push_swap.h bonus/checker.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE) 
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${NAME_BONUS}

${NAME_BONUS}: $(LIBFT) ${OBJ_BONUS}
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
