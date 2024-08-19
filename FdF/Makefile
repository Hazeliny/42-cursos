# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 17:33:07 by linyao            #+#    #+#              #
#    Updated: 2024/08/19 12:04:04 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
LIBFT_DIR 		:= $(LIB)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
#MINILIBX_DIR    := $(LIB)minilibx_macos/
MINILIBX_DIR	:= $(LIB)minilibx-linux/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -I mlx -L $(MINILIBX_DIR) -lmlx
HEADER 			:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
#OPENGL			:= -framework OpenGL -framework AppKit
OPENGL			:= -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	main get_next_line get_next_line_utils analyze_map \
				config_map ctrl_keys ctrl_mouse draw handle_errors \
				utils_ctrl utils_draw utils_draw2 utils_draw3 \
				utils_draw4 utils_draw5 utils_draw6 utils_draw7 utils_map
 

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

OBJF		=	.cache_exists

all:	makelibs
			@$(MAKE) $(NAME)

makelibs:	
			@$(MAKE) -C $(LIBFT_DIR)
			@$(MAKE) -C $(MINILIBX_DIR)

-include 	${DEPS}
$(NAME):	$(OBJ)		
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)		
			@echo "$(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)✨ FDF compiled!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			
$(LIBFT):
			@make -C $(LIBFT_DIR)
			@echo "$(GREEN)libft compiled!$(DEF_COLOR)"	
	
$(MINILIBX):
			@make -C $(MINILIBX_DIR)
			@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"			

clean:
			@make clean -sC $(LIBFT_DIR)
			@echo "$(CYAN)libft object and dependency files cleaned.$(DEF_COLOR)"
			@make clean -C $(MINILIBX_DIR)
			@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re bonus norm
