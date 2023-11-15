NAME			=	push_swap
BONUS			=	checker

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

SRC				=	lst_management operator operator2 push_swap pushswap_utils pushswap_utils2 ft_error chtoupsi_sort pushswap_utils3 create_linked_list main
BONUS_SRC		= 	checker_operator checker_operator2 lst_management operator operator2 push_swap pushswap_utils pushswap_utils2 ft_error chtoupsi_sort pushswap_utils3 create_linked_list checker

BONUS_SRCS		=	$(addsuffix .c, $(BONUS_SRC))
SRCS 			=	$(addsuffix .c, $(SRC))

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)
bonus:				$(BONUS)

$(NAME):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(BONUS):$(LIBFT)
			$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(BONUS)

re:					fclean all

.PHONY:				all  clean fclean re libft