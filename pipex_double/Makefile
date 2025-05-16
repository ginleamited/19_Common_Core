# Standard
NAME        = pipex
BONUS_NAME  = pipex_bonus

# Directories
LIBFT       = ./lib/libft.a
INC         = inc/
MANDATORY_DIR   = src/mandatory/
BONUS_DIR       = src/bonus/
OBJ_DIR     = obj/
MANDATORY_OBJ_DIR = $(OBJ_DIR)mandatory/
BONUS_OBJ_DIR = $(OBJ_DIR)bonus/

# Compiler and Flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I$(INC)
RM          = rm -f

# Source Files
MANDATORY_SRCS  = $(wildcard $(MANDATORY_DIR)*.c)
BONUS_SRCS      = $(wildcard $(BONUS_DIR)*.c)

# Object Files
MANDATORY_OBJS  = $(patsubst $(MANDATORY_DIR)%.c,$(MANDATORY_OBJ_DIR)%.o,$(MANDATORY_SRCS))
BONUS_OBJS      = $(patsubst $(BONUS_DIR)%.c,$(BONUS_OBJ_DIR)%.o,$(BONUS_SRCS))

# Rules
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)$(BONUS_NAME) compiled!$(NC)"

$(MANDATORY_OBJ_DIR)%.o: $(MANDATORY_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)Object files cleaned!$(NC)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)Executables cleaned!$(NC)"

re: fclean all

.PHONY: all bonus clean fclean re