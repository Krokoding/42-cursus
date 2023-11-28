NAME			=	pipex

NAME_BONUS		= 	pipex_bonus

CC				=	cc -fsanitize=address -g3
CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

SRC				=	mandatory/pipex mandatory/get_path

SRC_BONUS		=	bonus/pipex_bonus bonus/get_path_bonus

SRCS 			=	$(addsuffix .c, $(SRC))

SRCS_BONUS		=	$(addsuffix .c, $(SRC_BONUS))

LIBFT			=	libft.a

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME_BONUS):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT)  -o $(NAME_BONUS)


all:				$(NAME)

$(NAME):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT)  -o $(NAME)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all  clean fclean re libft