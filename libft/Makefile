NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I./

SOURCES_C =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_split.c ft_strjoin.c ft_strtrim.c

SOURCES_O = $(SOURCES_C:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES_O)
	ar -rc $(NAME) $(SOURCES_O)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(SOURCES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re