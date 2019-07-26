# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 14:02:38 by akolvakh          #+#    #+#              #
#    Updated: 2019/04/27 11:48:03 by akolvakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d 

CC = clang

FLAGS = -Wall -Werror -Wextra -I $(H) -o $(NAME)
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(H_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./libmlx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)includes/

H_LIST = wolf3d.h
H_DIR = ./includes/
H = $(addprefix $(H_DIR), $(H_LIST))

SRC_DIR = ./sources/
SRC_LIST = main.c\
core.c\
initialization.c\
system.c\
movement.c\
render.c\
controls.c\
parser.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GREEN) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN) $(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN) $(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(H)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).\c$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN) Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN) Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED) $(MINILIBX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED) $(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED) $(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
