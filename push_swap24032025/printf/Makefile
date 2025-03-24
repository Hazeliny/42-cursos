# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 14:00:39 by linyao            #+#    #+#              #
#    Updated: 2025/03/24 15:34:30 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
AR		=    ar rcs
CC		=    cc
CFLAGS	=    -g -Wall -Wextra -Werror -MMD -MF $(@:.o=.d)

LIB	=	header/ft_printf.h
SRCDIR	= src
DEPSDIR = deps
OBJDIR	= objs
LIBFTDIR	= libft
LIBFT	= $(LIBFTDIR)/libft.a
SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_bonus.c ft_printf_calculate.c ft_printf_calculate_falgs.c ft_printf_cases.c ft_printf_cases_bonus.c ft_printf_cases_bonus2.c ft_printf_malloc.c
OBJS	= $(addprefix $(OBJDIR)/, ${SRCS:.c=.o})
DEPS	= $(addprefix $(DEPSDIR)/, ${SRCS:.c=.d})

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET			= \033[m

all: $(LIBFT) $(NAME)

-include $(DEPS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@
	@mv objs/*.d deps/

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPSDIR):
	@mkdir $(DEPSDIR)

$(LIBFT):
	@printf "%b" "$(BLUE)$(@F)$(RESET)\n"
	@$(MAKE) --silent -C $(LIBFTDIR) bonus

$(NAME): $(OBJS) 
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

clean:
	@printf "%b" "$(BLUE)printf $(@)ing...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@rm -rf $(DEPSDIR)
	@$(MAKE) -C $(LIBFTDIR) clean --silent

fclean: clean
	@printf "%b" "$(BLUE)printf $(@)ing...$(RESET)\n"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean --silent

re: fclean all

bonus: all

.PHONY: all clean fclean re $(LIBFT)
