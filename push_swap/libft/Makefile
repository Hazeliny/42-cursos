# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 17:48:46 by linyao            #+#    #+#              #
#    Updated: 2025/03/23 20:03:24 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HBONUS = .bonus

INCLUDE = libft.h get_next_line.h

SRC = ft_atoi.c  ft_memchr.c ft_split.c ft_strncmp.c \
      ft_bzero.c ft_memcmp.c ft_strchr.c ft_strnstr.c \
      ft_calloc.c ft_memcpy.c ft_strdup.c ft_strrchr.c \
      ft_isalnum.c ft_memmove.c ft_striteri.c ft_strtrim.c \
      ft_isalpha.c ft_memset.c ft_strjoin.c ft_substr.c \
      ft_isascii.c ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
      ft_isdigit.c ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
      ft_isprint.c ft_putnbr_fd.c ft_strlen.c \
      ft_itoa.c ft_putstr_fd.c ft_strmapi.c \
	get_next_line.c get_next_line_utils.c

BONUS_FILES = ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
              ft_lstnew.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
              ft_lstsize.c ft_lstclear.c

BONUS_OBJ = $(BONUS_FILES:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(HBONUS)
	touch $(HBONUS)

$(HBONUS): $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $^

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ) $(BONUS_OBJ)
		rm -rf $(HBONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
