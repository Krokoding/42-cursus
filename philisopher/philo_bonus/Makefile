NAME_BONUS		=	philo_bonus

NAME_FCLEAN		= 	philo

CC				=	gcc -g
CFLAGS			=	-lpthread -fsanitize=address -g3
RM				=	rm -rf

SRC_BONUS		=	philosopher_bonus philosopher_utils_bonus initialisation_bonus my_func_bonus eat_sleep_and_think_bonus getters_setters_bonus process_management_bonus dinner_bonus
SRCS_BONUS		=	$(addsuffix .c, $(SRC))

bonus:				$(NAME_BONUS)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

clean:

fclean:				clean
					$(RM) $(NAME_BONUS) 

re:					fclean all

.PHONY:				all clean fclean re