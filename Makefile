BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
RESET = \033[0m

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./lib/libft
LIBFT_A = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_A = $(FT_PRINTF_DIR)/libftprintf.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(OBJS)
	@echo "Linking..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) compiled successfully!$(RESET)"

$(LIBFT_A):
	@echo "Compiling libft"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(RESET)"

$(FT_PRINTF_A):
	@echo "Compiling ft_printf"
	@$(MAKE) -s -C $(FT_PRINTF_DIR)
	@echo "$(RESET)"

all: $(NAME)

clean:
	@echo "$(BOLD)Cleaning...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) clean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(BOLD)$(RED)Full cleaning...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
