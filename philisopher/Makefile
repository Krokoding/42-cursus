NAME			=	philo


CC				=	cc
CFLAGS			=	-lpthread

RM				=	rm -rf

SRC				=	philosopher sleep_and_think

SRCS 			=	$(addsuffix .c, $(SRC))

all:				$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS) 

re:					fclean all

.PHONY:				all  clean fclean re libft