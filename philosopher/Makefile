NAME				=	philo
NAME_BONUS			=	philo_bonus

NAME_FCLEAN			= 	philo
NAME_FCLEAN_BONUS 	= 	philo_bonus

CC				=	gcc -g
CFLAGS			=	-lpthread -fsanitize=thread -g3
RM				=	rm -rf

SRC				=	mandatory/philo/philosopher mandatory/philo/philosopher_utils mandatory/philo/initialisation mandatory/philo/my_func mandatory/philo/eat_sleep_and_think mandatory/philo/getters_setters mandatory/philo/thread_management mandatory/philo/dinner
SRCS 			=	$(addsuffix .c, $(SRC))

SRC_BONUS		=	bonus/philo_bonus/philosopher_bonus bonus/philo_bonus/philosopher_utils_bonus bonus/philo_bonus/initialisation_bonus bonus/philo_bonus/my_func_bonus bonus/philo_bonus/eat_sleep_and_think_bonus bonus/philo_bonus/getters_setters_bonus bonus/philo_bonus/process_management_bonus bonus/philo_bonus/dinner_bonus
SRCS_BONUS		=	$(addsuffix .c, $(SRC))

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME_BONUS):
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:				clean
					$(RM) $(NAME_FCLEAN) $(NAME_FCLEAN_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re