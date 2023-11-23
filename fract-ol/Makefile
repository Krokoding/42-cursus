NAME			=	fractol

CC				=	clang -fsanitize=address -g3
CFLAGS			=	-lX11 -lXext -lmlx

RM				=	rm -rf

SRC				=	fractol zoom_movement color utils ensemble handle_entry

SRCS 			=	$(addsuffix .c, $(SRC))

LIBFT			=	libft.a

all:				$(NAME)

$(NAME):$(LIBFT)
			$(CC) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all  clean fclean re libft