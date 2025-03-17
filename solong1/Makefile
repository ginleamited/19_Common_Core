# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 22:45:18 by jilin             #+#    #+#              #
#    Updated: 2025/03/12 20:29:25 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= so_long

# Directories
LIBFT				= ./lib/libft.a
MLX_PATH			= ./mlx
MLX					= $(MLX_PATH)/libmlx.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3 #-fsanitize=address
RM					= rm -f

# Source Files
SRCS	=	$(SRC_DIR)main.c \
				$(SRC_DIR)backtracking.c \
				$(SRC_DIR)free_exit.c \
				$(SRC_DIR)init_render.c \
				$(SRC_DIR)parsing_map.c \
				$(SRC_DIR)player_movement.c \
				$(SRC_DIR)utils.c


# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Include directories
INCLUDES			= -I$(INC) -I$(MLX_PATH)

# Libraries
LIBS = -L./lib -lft -L./mlx -lmlx -lX11 -lXext -lm

# Colors
GREEN   			= "\\033[32m"
YELLOW  			= "\\033[33m"
NC      			= "\\033[0m"

# Progress Bar
TOTAL_FILES 		:= $(words $(SRCS))
CURRENT_FILE 		:= 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling so_long... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

# SO_LONG ASCII Art
SO_LONG_LOGO = "\033[5;36m\
███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗  \n\
██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝  \n\
███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗ \n\
╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║ \n\
███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝ \n\
╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝  \n\
\033[0m"


# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./lib -s

$(MLX):
					@make -C $(MLX_PATH) -s

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT) $(MLX)
					@printf "\n"
					@printf $(SO_LONG_LOGO)
					@echo "$(GREEN)Linking objects to create executable...$(NC)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)
					@echo "$(GREEN)Executable $(NAME) created!$(NC)"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
					$(call progress_bar)

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./lib --no-print-directory
					@make clean -C $(MLX_PATH) --no-print-directory

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(MLX)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re