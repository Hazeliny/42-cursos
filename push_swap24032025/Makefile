# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 13:56:48 by linyao            #+#    #+#              #
#    Updated: 2025/03/24 15:22:14 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap
CHECKER	= checker
AR       = ar
ARFLAGS  = -rcs
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g
OFLAGS   = -MMD -MF $(@:.o=.d)

SRCDIR   = src
UTILSDIR = utils
SORTSDIR = sorts
MOVEDIR  = movements
DEPSDIR  = deps
OBJDIR   = objs
OUTILSDIR = $(OBJDIR)/outils
OSORTSDIR = $(OBJDIR)/osorts
OMOVEDIR  = $(OBJDIR)/omove
PRINTFDIR = printf
BONUSDIR	= bonus

LIBCHECK	= bonus/checker_bonus.h bonus/get_next_line_bonus.h
LIB	=	header/push_swap.h
PRINTF   = $(PRINTFDIR)/libftprintf.a
MOVE     = ft_push.c ft_rev_rotate.c ft_rotate.c ft_swap.c
SORTS    = ft_sorts.c ft_sorts_mid_top.c ft_sorts_mid_bot.c \
           ft_sorts_min_bot.c ft_sorts_min_top.c ft_sorts_max_top.c \
           ft_sorts_max_bot.c ft_sorts_mis_min.c ft_sorts_min_top2.c \
			ft_sorts_extras.c ft_sorts_extras2.c
UTILS    = ft_base.c ft_numbers.c ft_push_error.c\
		   ft_utils.c
SRCS     = ft_analisis.c ft_move.c ft_share.c ft_split.c ft_deals_correct.c \
			ft_utils2.c ft_sorted.c
BONUSSRC	= ft_checker.c ft_utils_bonus.c ft_push_bonus.c \
			  ft_rev_rotate_bonus.c ft_rotate_bonus.c ft_swap_bonus.c \
			  get_next_line_bonus.c

OBJCHECK	= $(addprefix $(BONUSDIR)/, $(BONUSSRC:.c=.o))
OUTILS   = $(addprefix $(OUTILSDIR)/, $(UTILS:.c=.o))
OSORTS   = $(addprefix $(OSORTSDIR)/, $(SORTS:.c=.o))
OMOVE    = $(addprefix $(OMOVEDIR)/, $(MOVE:.c=.o))
OBJS     = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS     = $(addprefix $(DEPSDIR)/, $(SRCS:.c=.d) $(MOVE:.c=.d) $(SORTS:.c=.d) $(UTILS:.c=.d))
BONUSDEPS	= $(addprefix $(BONUSDIR)/, $(BONUSSRC:.c=.d))
MAIN     = ft_push_swap.c

RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
PURPLE   = \033[0;35m
CYAN     = \033[0;36m
RESET    = \033[m

all: $(PRINTF) $(NAME) $(LIB) Makefile

bonus: $(PRINTF) $(CHECKER) $(LIB) $(LIBCHECK) Makefile

-include $(DEPS)

$(CHECKER): $(OUTILS) $(OBJCHECK)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(PRINTF) $(OBJCHECK) $(OUTILS) $(PRINTF) -o $(CHECKER)

$(OBJCHECK): $(BONUSDIR)/%.o : $(BONUSDIR)/%.c 
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c Makefile | $(OBJDIR) $(DEPSDIR) 
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv objs/*.d deps/

$(OUTILS): $(OUTILSDIR)/%.o : $(UTILSDIR)/%.c | $(OUTILSDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OUTILSDIR)/*.d deps/

$(OSORTS): $(OSORTSDIR)/%.o : $(SORTSDIR)/%.c | $(OSORTSDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OSORTSDIR)/*.d deps/

$(OMOVE): $(OMOVEDIR)/%.o : $(MOVEDIR)/%.c | $(OMOVEDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OMOVEDIR)/*.d deps/

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OUTILSDIR):
	@mkdir -p $(OUTILSDIR)

$(OSORTSDIR):
	@mkdir -p $(OSORTSDIR)

$(OMOVEDIR):
	@mkdir -p $(OMOVEDIR)

$(DEPSDIR):
	@mkdir -p $(DEPSDIR)

$(PRINTF):
	@printf "%b" "$(BLUE)$(@F)$(RESET)\n"
	@$(MAKE) --silent -C $(PRINTFDIR)
$(NAME): $(MAIN) $(OBJS) $(OMOVE) $(OUTILS) $(OSORTS)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(MAIN) $(PRINTF) $(OBJS) $(OMOVE) $(OSORTS) $(OUTILS) $(PRINTF) -o $(NAME)

clean:
	@printf "%b" "$(BLUE)Cleaning objects...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@rm -rf $(DEPSDIR)
	@rm -rf $(OMOVEDIR)
	@rm -rf $(OSORTSDIR)
	@rm -rf $(OUTILSDIR)
	@rm -rf $(OBJCHECK)
	@rm -rf $(BONUSDEPS)
	@$(MAKE) -C $(PRINTFDIR) clean --silent

fclean: clean
	@printf "%b" "$(BLUE)Cleaning all files...$(RESET)\n"
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@$(MAKE) -C $(PRINTFDIR) fclean --silent

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus $(PRINTF)
