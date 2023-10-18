NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I./includes

SOURCES_C =	isalpha.c isdigit.c isalnum.c isascii.c isprint.c strlen.c memset.c bzero.c memcpy.c memmove.c strlcpy.c strlcat.c toupper.c tolower.c strchr.c strrchr.c strncmp.c memchr.c memcmp.c strnstr.c atoi.c

SOURCES_O = $(SOURCES_C:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES_O)
	ar -rc $(NAME) $(SOURCES_O)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOURCES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re