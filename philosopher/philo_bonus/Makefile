NAME_BONUS			=	philo_bonus

NAME_FCLEAN_BONUS 	= 	philo_bonus

CC				=	gcc -g
CFLAGS			=	-lpthread -Wall -Werror -Wextra #-fsanitize=thread -g3
RM				=	rm -f

SRC_BONUS		=	philosopher_bonus philosopher_utils_bonus initialisation_bonus my_func_bonus eat_sleep_and_think_bonus getters_setters_bonus process_management dinner_bonus
SRCS_BONUS		=	$(addsuffix .c, $(SRC_BONUS))

all:				$(NAME_BONUS)

$(NAME_BONUS):
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

clean:

fclean:				clean
					$(RM) $(NAME_FCLEAN_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re