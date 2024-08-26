# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 11:43:44 by linyao            #+#    #+#              #
#    Updated: 2024/08/26 19:03:12 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#define source file and object file
NAME = pipex
BONUS_NAME = pipex_bonus
SRCS = src/pipex.c src/utils_pipex.c
BONUS_SRCS = src/pipex_bonus.c src/utils_pipex_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#define libft path
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#define header file
INCLUDE = src/pipex.h src/pipex_bonus.h \
	libft/libft.h libft/ft_printf.h libft/get_next_line.h \
	libft/get_next_line_bonus.h

#define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I src/ #-fsanitize=address

#compile the main project
all: $(NAME)

#object:$(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

#object: bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

#object: compile libft library
$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#object: clean files.o
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

#object: clean all the produced files including executable files
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

#object: re-compile all the files
re: fclean all

.PHONY: all clean fclean re bonus
