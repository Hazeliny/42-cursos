# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 19:03:57 by linyao            #+#    #+#              #
#    Updated: 2024/06/25 16:07:41 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = libft/libft.h ft_printf.h

SRC = ft_printf.c ft_convert.c ft_convert2.c
TEST_SRC = test_main.c test_types.c

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $@ $^
	@cp $(LIBFT) .
	@mv libft.a $(NAME)
	@ar -r $(NAME) $(OBJ)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) test_program
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: $(LIBFT) $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -o test_program $(OBJ) $(TEST_OBJ) $(LIBFT)
	./test_program

.PHONY: all clean fclean re test
