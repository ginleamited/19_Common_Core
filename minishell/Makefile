# Standard
NAME				= minishell

# Directories
LIBFT				= ./lib/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3
DEBUG_FLAGS			= -fsanitize=address
RM					= rm -f

# Source and Object Files
SRCS				= $(shell find $(SRC_DIR) -name '*.c')
OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
DEPS				= $(OBJ:.o=.d)

# Libraries
INCLUDES			= -I$(INC) -I/usr/include/readline
LIBS				= -L./lib -lft -lreadline

# Colors
GREEN   			= "\\033[32m"
YELLOW  			= "\\033[33m"
NC      			= "\\033[0m"

# Progress Bar
TOTAL_FILES 		:= $(words $(SRCS))
CURRENT_FILE 		:= 0

define progress_bar
    $(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    printf "\r$(YELLOW)Compiling minishell... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
    $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
    @if [ "$(CURRENT_FILE)" -eq "$(TOTAL_FILES)" ]; then echo ""; fi
endef

# MINISHELL ASCII Art
MINISHELL_LOGO = "\033[1;36m\
███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗      \n\
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║      \n\
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║      \n\
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║      \n\
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗ \n\
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \n\
\033[0m"

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./lib -s

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
					@printf "\n"
					@printf $(MINISHELL_LOGO)
					@echo "$(GREEN)Linking objects to create executable...$(NC)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)
					@echo "$(GREEN)Executable $(NAME) created!$(NC)"

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD
					@$(call progress_bar)

debug:				CFLAGS += $(DEBUG_FLAGS)
debug:				re
					@echo "$(GREEN)Debug build with AddressSanitizer created!$(NC)"

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
					@echo "$(YELLOW)Running Norminette...$(NC)"
					@norminette $(SRC_DIR) $(INC) || true
					@echo "$(GREEN)Norminette check complete!$(NC)"

# Include dependency files
-include $(DEPS)

# Phony targets
.PHONY:				start all clean fclean re norm debug