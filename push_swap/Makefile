# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 16:29:05 by jilin             #+#    #+#              #
#    Updated: 2024/12/10 17:06:19 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
INCDIR = includes libft ft_printf
OBJDIR = obj
LIBFTDIR = libft
FTPRINTFDIR = ft_printf

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Output binary
NAME = push_swap

# Include paths
INCLUDES = $(addprefix -I, $(INCDIR))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(FTPRINTFDIR) -lftprintf -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(FTPRINTF):
	make -C $(FTPRINTFDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)
	make clean -C $(FTPRINTFDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(FTPRINTFDIR)

re: fclean all

.PHONY: all clean fclean re
