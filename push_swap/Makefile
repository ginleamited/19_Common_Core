# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:16:10 by jilin             #+#    #+#              #
#    Updated: 2025/02/24 03:19:07 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)cmd/to_push.c \
						$(SRC_DIR)cmd/to_rev_rotate.c \
						$(SRC_DIR)cmd/to_rotate.c \
						$(SRC_DIR)cmd/to_sort.c \
						$(SRC_DIR)cmd/to_sort3.c \
						$(SRC_DIR)cmd/to_swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/errors.c \
						$(SRC_DIR)push_swap/init_a.c \
						$(SRC_DIR)push_swap/init_b.c \
						$(SRC_DIR)push_swap/init.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/utils.c \

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re