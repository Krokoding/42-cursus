NAME			=	pipex

CC				=	cc
CFLAGS			=	-fsanitize=address -g3

RM				=	rm -rf

SRC				=	pipex pipex_utils

SRCS 			=	$(addsuffix .c, $(SRC))

LIBFT			=	libft.a

all:				$(NAME)

$(NAME):$(LIBFT)
			$(CC) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all  clean fclean re libft