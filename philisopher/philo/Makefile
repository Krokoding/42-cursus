NAME			=	philo

NAME_FCLEAN		= philosopher/philo

CC				=	gcc -g
CFLAGS			=	-lpthread -fsanitize=address -g3
RM				=	rm -rf

SRC				=	philosopher philosopher_utils initialisation my_func eat_sleep_and_think getters_setters thread_management dinner
SRCS 			=	$(addsuffix .c, $(SRC))

all:				$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re