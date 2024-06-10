NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#text style
BOLD = \033[1m
GREEN = \033[92m
RESET = \033[0m

SRCS = ft_putchar_fd.c ft_putnbr_fd.c \
       ft_putstr_fd.c ft_putnbr_base.c \
       ft_printf.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(BOLD)$(GREEN)$(NAME) created successfully!$(RESET)"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< 

all : $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
