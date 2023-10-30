NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft

DEPS = $(LIBFT_DIR)/libft.a

SOURCES_C = ft_print_nbr.c ft_print_p.c ft_print_unbr.c ft_print_x.c ft_printf_utils.c ft_printf.c ft_printf.h

SOURCES_O = $(SOURCES_C:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES_O) $(DEPS)
	ar rcs $@ $(SOURCES_O)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf	$(NAME)

re: fclean all

.PHONY: all clean fclean re