CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET			= \033[m

AR = ar rcs
LIB = libft.h

ifndef BONUS
	OBJ = $(SRC:.c=.o)
else
	OBJ = $(SRC:.c=.o) $(SRC_BONUS:.c=.o)
endif

OBJB = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(LIB) Makefile
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "%b" "$(BLUE)libft $(@)ing...$(RESET)\n"
	rm -f $(OBJ) $(OBJB)

fclean: clean
	@printf "%b" "$(BLUE)libft $(@)ing...$(RESET)\n"
	rm -f $(NAME)

re: fclean all

bonus:
	@make BONUS=1 --no-print-directory

.PHONY: all clean fclean re bonus

