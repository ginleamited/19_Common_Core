# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:51:06 by jilin             #+#    #+#              #
#    Updated: 2024/10/23 17:51:06 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

CC = cc
# compiler use cc
CFLAGS = -Wall -Wextra -Werror
# flags

SRC = ft_isalpha.c \
			ft_isdigit.c \
            ft_isalnum.c \
            ft_isascii.c \
            ft_isprint.c \
            ft_strlen.c \
            ft_memset.c \
            ft_bzero.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_strlcpy.c \
            ft_strlcat.c \
            ft_toupper.c \
	      	ft_tolower.c \
	      	ft_strchr.c \
	      	ft_strrchr.c \
	      	ft_strncmp.c \
	      	ft_memchr.c \
	      	ft_memcmp.c \
	      	ft_strnstr.c \
	      	ft_atoi.c \
	      	ft_calloc.c \
	      	ft_strdup.c \
		  	ft_substr.c \
		  	ft_strjoin.c \
		  	ft_strtrim.c \
		  	ft_split.c \
		  	ft_itoa.c \
		  	ft_strmapi.c \
		  	ft_striteri.c \
		  	ft_putchar_fd.c \
		  	ft_putstr_fd.c \
		  	ft_putendl_fd.c \
		  	ft_putnbr_fd.c \
# source files

BONUS_SRC = ft_lstnew_bonus.c \
		  		ft_lstadd_front_bonus.c \
		  		ft_lstsize_bonus.c \
		 		ft_lstlast_bonus.c \
		  		ft_lstadd_back_bonus.c \
		  		ft_lstdelone_bonus.c \
		  		ft_lstclear_bonus.c \
		  		ft_lstiter_bonus.c \
		  		ft_lstmap_bonus.c \
# bonus files

OBJ = $(SRC:.c=.o)
# created by replacing .c with .o
BONUS_OBJ = $(BONUS_SRC:.c=.o)
# created by replacing .c with .o

HEADER = libft.h
# header file on the top of each file
NAME = libft.a
# name of output library

ifeq ($(BONUS),1)
	OBJ_FILES = $(OBJ) $(BONUS_OBJ)
else
	OBJ_FILES = $(OBJ)
endif
# OBJ_FILES: Determines whether to include 
# BONUS_OBJ files based on the BONUS flag

# RULES

all: $(NAME)
# if not up-to-date, run the rule to build it

$(NAME): $(OBJ_FILES)
# build static library libft.a by archiving all the
# object files in $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)
# ar -rc creates or replace the library $(NAME) with 
# the given object files ($(OBJ_FILES)).

%.o: %.c $(HEADER)
# compiles each .c source file into a .o object file
	$(CC) $(CFLAGS) -c $< -o $@
# $< is the first prerequisite (the .c file), 
# and $@ is the target (the .o file).

# BONUS RULES

bonus:
	$(MAKE) BONUS=1 all
# Sets the BONUS flag to 1 and calls the all target 
# to include bonus object files in the library

# CLEANING RULES

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
# Removes all object files ($(OBJ) and $(BONUS_OBJ))

fclean: clean
	rm -f $(NAME)
# Calls clean and also removes the library file $(NAME)

re: fclean all
# Rebuilds the library by first calling fclean 
# (clean everything) and then all (rebuild)

.PHONY: all clean fclean re
# tells make that all, clean, fclean, and re are not 
# actual files, but rather labels for commands, ensuring 
# that make always executes them
