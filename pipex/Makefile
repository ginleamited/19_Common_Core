# Standard
NAME				= pipex
BONUS_NAME			= pipex_bonus

# Directories
LIBFT				= ./lib/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Subdirectories
MANDATORY_DIR		= mandatory/
BONUS_DIR			= bonus/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3
DEBUG_FLAGS			= -fsanitize=address
RM					= rm -f

# Source Files
MANDATORY_SRCS		= $(wildcard $(SRC_DIR)$(MANDATORY_DIR)*.c)
BONUS_SRCS			= $(wildcard $(SRC_DIR)$(BONUS_DIR)*.c)

# Object Files
MANDATORY_OBJ		= $(patsubst $(SRC_DIR)$(MANDATORY_DIR)%.c, $(OBJ_DIR)$(MANDATORY_DIR)%.o, $(MANDATORY_SRCS))
BONUS_OBJ			= $(patsubst $(SRC_DIR)$(BONUS_DIR)%.c, $(OBJ_DIR)$(BONUS_DIR)%.o, $(BONUS_SRCS))
DEPS				= $(MANDATORY_OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

# Libraries
INCLUDES			= -I$(INC)
LIBS				= -L./lib -lft

# Colors
GREEN				= \033[32m
YELLOW				= \033[33m
CYAN				= \033[1;36m
RESET				= \033[0m

# Progress tracking
TOTAL_MANDATORY		:= $(words $(MANDATORY_SRCS))
TOTAL_BONUS			:= $(words $(BONUS_SRCS))

# Build rules
all:				$(LIBFT) $(NAME)

bonus:				$(LIBFT) $(BONUS_NAME)

$(LIBFT):
					@make -C ./lib --no-print-directory

$(NAME):			$(MANDATORY_OBJ)
					@printf "\n"
					@echo "$(CYAN)Linking mandatory objects...$(RESET)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(MANDATORY_OBJ) $(LIBS) -o $(NAME)
					@echo "$(GREEN)Mandatory executable $(NAME) created!$(RESET)"

$(BONUS_NAME):		$(BONUS_OBJ)
					@printf "\n"
					@echo "$(CYAN)Linking bonus objects...$(RESET)"
					@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) $(LIBS) -o $(BONUS_NAME)
					@echo "$(GREEN)Bonus executable $(BONUS_NAME) created!$(RESET)"

# Compilation rules with progress tracking
$(OBJ_DIR)$(MANDATORY_DIR)%.o: $(SRC_DIR)$(MANDATORY_DIR)%.c
					@mkdir -p $(@D)
					@printf "\r$(YELLOW)Compiling mandatory... [%d/%d] %-50s$(RESET)" \
						$(shell ls -1 $(OBJ_DIR)$(MANDATORY_DIR)*.o 2>/dev/null | wc -l | tr -d ' ') \
						$(TOTAL_MANDATORY) \
						"$<"
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD

$(OBJ_DIR)$(BONUS_DIR)%.o: $(SRC_DIR)$(BONUS_DIR)%.c
					@mkdir -p $(@D)
					@printf "\r$(YELLOW)Compiling bonus... [%d/%d] %-50s$(RESET)" \
						$(shell ls -1 $(OBJ_DIR)$(BONUS_DIR)*.o 2>/dev/null | wc -l | tr -d ' ') \
						$(TOTAL_BONUS) \
						"$<"
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD

# Clean rules
clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./lib --no-print-directory
					@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean:				clean
					@$(RM) $(NAME) $(BONUS_NAME)
					@$(RM) $(LIBFT)
					@echo "$(GREEN)Executables and libraries cleaned!$(RESET)"

re:					fclean all

# Include dependency files
-include $(DEPS)

.PHONY:				all bonus clean fclean re