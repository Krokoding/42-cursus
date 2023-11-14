NAME			=	push_swap

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

SRC				=	ft_itoab lst_management operator operator2 push_swap pushswap_utils pushswap_utils2 /
					ft_error main chtoupsi_sort pushswap_utils3
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