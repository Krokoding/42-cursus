NAME			=	philo
NAME_BONUS		=	philo_bonus

NAME_FCLEAN		= philosopher/philo
NAME_FCLEAN_BONUS = philosopher_bonus/philo_bonus

CC				=	gcc -g
CFLAGS			=	-lpthread -fsanitize=thread -g3
RM				=	rm -rf

SRC				=	philosopher/philosopher philosopher/philosopher_utils philosopher/initialisation philosopher/my_func philosopher/eat_sleep_and_think philosopher/getters_setters philosopher/thread_management philosopher/dinner
SRCS 			=	$(addsuffix .c, $(SRC))

SRC_BONUS		=	philo_bonus/philosopher_bonus philo_bonus/philosopher_utils_bonus philo_bonus/initialisation_bonus philo_bonus/my_func_bonus philo_bonus/eat_sleep_and_think_bonus philo_bonus/getters_setters_bonus philo_bonus/process_management_bonus philo_bonus/dinner_bonus
SRCS_BONUS		=	$(addsuffix .c, $(SRC))

all:				$(NAME)

bonus:
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME_FCLEAN) $(NAME_FCLEAN_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re