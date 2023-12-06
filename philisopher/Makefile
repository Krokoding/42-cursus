NAME			=	philo


CC				=	cc
CFLAGS			=	-lpthread 

RM				=	rm -rf

SRC				=	philosopher eat_sleep_and_think rotation_of_action thread_management philosopher_utils

SRCS 			=	$(addsuffix .c, $(SRC))

all:				$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) libft.a -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS) 

re:					fclean all

.PHONY:				all  clean fclean re libft