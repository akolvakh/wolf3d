# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 14:02:38 by akolvakh          #+#    #+#              #
#    Updated: 2019/04/27 11:47:38 by akolvakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

CC = clang

FLAGS = -Wall -Werror -Wextra -c

INCLUDES = -I$(H_DIR)
H_LIST = libft.h
H_DIR = ./includes/
H = $(addprefix $(H_DIR), $(H_LIST))

SRC_DIR = ./sources/
SRC_LIST = ft_atoi.c\
ft_bzero.c\
ft_free.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_count_words.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_sqrt.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strnchr.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_swap.c\
ft_tolower.c\
ft_toupper.c\
ft_strndup.c\
get_next_line.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n$(NAME): object files were created"
	@echo "$(NAME): $(NAME) was created"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(OBJ_DIR) was created"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(H)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo ".\c"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(OBJ_DIR) was deleted"
	@echo "$(NAME): object files were deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(NAME) was deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all
