# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 18:25:04 by jilin             #+#    #+#              #
#    Updated: 2024/11/07 00:07:33 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc -Wall -Wextra -Werror

LIB = ar -rcs

SRC = ft_printf.c functions.c functions_hex.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(LIB) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
