NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I./

SOURCES_C =	ft_putnbr_fd.c ft_putendl_fd.c ft_isalpha.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c \
 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
 ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
 ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_itoa.c ft_split.c \
 ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoab.c ft_atoli.c get_next_line.c get_next_line_utils.c \
 ft_printf.c ft_print_nbr.c ft_print_p.c ft_print_x.c ft_print_unbr.c

SOURCES_O = $(SOURCES_C:.c=.o)

BONUS_FILES	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ	=	$(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES_O)
	ar rcs $(NAME) $(SOURCES_O)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

bonus:		$(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)

clean:
	rm -f $(SOURCES_O) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re