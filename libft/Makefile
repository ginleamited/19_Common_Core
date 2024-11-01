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

CC = cc
CFLAGS = -Wall -Wextra -Werror

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

BONUS_SRC = ft_lstnew_bonus.c \
		  		ft_lstadd_front_bonus.c \
		  		ft_lstsize_bonus.c \
		 		ft_lstlast_bonus.c \
		  		ft_lstadd_back_bonus.c \
		  		ft_lstdelone_bonus.c \
		  		ft_lstclear_bonus.c \
		  		ft_lstiter_bonus.c \
		  		ft_lstmap_bonus.c \


OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEADER = libft.h

NAME = libft.a

ifeq ($(BONUS),1)
	OBJ_FILES = $(OBJ) $(BONUS_OBJ)
else
	OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER)\
      $(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) BONUS=1 all

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re