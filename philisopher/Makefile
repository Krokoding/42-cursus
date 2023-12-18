NAME			=	philo


CC				=	gcc -g
CFLAGS			=	-lpthread -fsanitize=thread -g3
RM				=	rm -rf

SRC				=	philosopher/philosopher philosopher/philosopher_utils philosopher/initialisation philosopher/my_func philosopher/eat_sleep_and_think philosopher/getters_setters philosopher/thread_management philosopher/dinner
SRCS 			=	$(addsuffix .c, $(SRC))

all:				$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re