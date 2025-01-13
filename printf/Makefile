# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 18:25:04 by jilin             #+#    #+#              #
#    Updated: 2025/01/13 18:56:24 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs
RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = ft_printf.c functions.c functions_hex.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

HEAD = ./inc/

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(NAME)	: $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all