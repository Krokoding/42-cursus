NAME			=	pipex

NAME_BONUS		= 	pipex_bonus

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -rf

SRC				=	mandatory/pipex mandatory/get_path

SRC_BONUS		=	bonus/pipex_bonus bonus/get_path_bonus bonus/pipex_utils_bonus

SRCS 			=	$(addsuffix .c, $(SRC))

SRCS_BONUS		=	$(addsuffix .c, $(SRC_BONUS))

LIBFT_PATH		=	libft

LIBFT			=	libft/libft.a

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME_BONUS):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT)  -o $(NAME_BONUS)


all:				$(NAME)

$(NAME):$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):$(LIBFT)
			make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS) 
					make fclean -C $(LIBFT_PATH)

re:					fclean all

.PHONY:				all  clean fclean re libft