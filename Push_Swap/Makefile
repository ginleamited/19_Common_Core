# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/07 14:18:24 by jilin             #+#    #+#              #
#    Updated: 2024/12/07 14:19:49 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc -Wall -Wextra -Werror

LIB = ar -rcs

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(LIB) $(NAME) $(OBJ)

%.o: %.c push_swap.h
	$(CC) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
