NAME				=	philo
NAME_BONUS			=	philo_bonus

NAME_FCLEAN			= 	philo
NAME_FCLEAN_BONUS 	= 	philo_bonus

CC				=	gcc -g
CFLAGS			=	-lpthread #-fsanitize=thread -g3
RM				=	rm -f

SRC				=	mandatory/philo/philosopher mandatory/philo/philosopher_utils mandatory/philo/initialisation mandatory/philo/my_func mandatory/philo/eat_sleep_and_think mandatory/philo/getters_setters mandatory/philo/thread_management mandatory/philo/dinner
SRCS 			=	$(addsuffix .c, $(SRC))

all:				$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME_FCLEAN) $(NAME_FCLEAN_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re