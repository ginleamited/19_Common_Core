# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jilin <jilin@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 22:45:18 by jilin             #+#    #+#              #
#    Updated: 2025/03/26 16:12:08 by jilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= pipex

# Directories
LIBFT				= ./lib/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3 #-fsanitize=address
RM					= rm -f

# Source Files
SRCS				= $(SRC_DIR)main.c

# Object Files
OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Libraries
INCLUDES			= -I$(INC)
LIBS				= -L./lib -lft

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
PIPEX_LOGO = "\033[5;36m\
██████╗ ██╗██████╗ ███████╗██╗  ██╗ \n\
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝ \n\
██████╔╝██║██████╔╝█████╗   ╚███╔╝  \n\
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗  \n\
██║     ██║██║     ███████╗██╔╝ ██╗ \n\
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝ \n\
\033[0m"

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./lib -s

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
					@printf "\n"
					@printf $(PIPEX_LOGO)
					@echo "$(GREEN)Linking objects to create executable...$(NC)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)
					@echo "$(GREEN)Executable $(NAME) created!$(NC)"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
					@echo "$(YELLOW)Compiling $<...$(NC)"

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./lib --no-print-directory
					@echo "$(GREEN)Object files cleaned!$(NC)"

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "$(GREEN)Executable and libraries cleaned!$(NC)"

re:					fclean all

norm:
					@norminette $(SRC_DIR) $(INC) | grep -v "OK" || echo "$(GREEN)Norminette OK!$(NC)"

# Phony targets
.PHONY:				start all clean fclean re norm