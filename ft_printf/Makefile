# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 18:25:04 by jilin             #+#    #+#              #
#    Updated: 2024/11/04 17:39:29 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

HEADER =printf.h
# header file on the top of each file
NAME = libftprintf.a
# name of output library

CC = cc
# compiler use cc
CFLAGS = -Wall -Wextra -Werror
# flags

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MAKE_LIB = ar -rcs
# ar -rc creates or replace the library $(NAME) with 
# the given object files ($(OBJ_FILES)).

INCS = .

SRC = ft_printf.c \
		ft_

OBJ = $(SRC:.c=.o)
# created by replacing .c with .o

bonus : all

# RULES

all: $(NAME)
# if not up-to-date, run the rule to build it

$(NAME): $(OBJ) $(LIBFT)
		$(MAKE_LIB) $(NAME) $(OBJ)
# build static library libft.a by archiving all the
# object files in $(OBJ)

%.o: %.c
# compiles each .c source file into a .o object file
	$(CC) $(CFLAGS) -c $< -I$(INCS)
# $< is the first prerequisite (the .c file), 

$(LIBFT) :
		cd $(LIBFT_PATH) && make
		cp $(LIBFT) $(NAME)

# CLEANING RULES

clean:
	rm -f $(OBJ) $(NAME)
# Removes all object files ($(OBJ) and $(BONUS_OBJ))

fclean: clean
	cd $(LIBFT_PATH) && make fclean
# Calls clean and also removes the library file $(NAME)

re: fclean all
# Rebuilds the library by first calling fclean 
# (clean everything) and then all (rebuild)

.PHONY: all clean fclean re
# tells make that all, clean, fclean, and re are not 
# actual files, but rather labels for commands, ensuring 
# that make always executes them
