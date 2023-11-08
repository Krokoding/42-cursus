NAME			=	push_swap

CC				=	gcc -fsanitize=address -g3
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

SRC				=	ft_itoab lst_management operator push_swap pushswap_utils main
SRCS 			=	$(addsuffix .c, $(SRC))

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)

$(NAME):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all  clean fclean re libft