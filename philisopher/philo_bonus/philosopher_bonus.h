/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/17 17:21:31 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>



typedef struct s_data	t_data;

typedef struct s_timer
{
	long	s;
	long	e;
	long	t;
	long	d;
}	t_timer;

typedef struct s_philos
{
	long			n;
	long			time_left;
	bool			*previous_fork;
	bool			*next_fork;
	long			meal_count;
	t_data			*data;
	long			last_meal;
	bool			full;
}	t_philos;

struct s_data
{
	bool			end;
	bool			allthread_creat;
	bool			all_full;
	bool			*fork;	
	sem_t			*fork_sem;
	long			n_o_p;
	long			start;
	long			max_meal;
	long			first_iteration;
	sem_t			*dead_lock;
	sem_t			*data_lock;
	sem_t			*no_eat_when_die;
	sem_t			*msg_lock;
	t_philos		*philo;
	t_timer			timer;
};

typedef enum e_eatopcode
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
}	t_eatopcode;

typedef enum e_opcode
{
	CREATE,
	JOIN,
	DESTROY,
	INIT,
	LOCK,
	UNLOCK,
}	t_opcode;

// error handling
int		msg_exit(char *str);

// initialisation
int		initialisation(int ac, char **av, t_data *d);
int		parsing(int ac, char **av, t_data *d);
long	ft_atoi(const char *nptr);
int		philo_init(int ac, char **av, t_data *d);
int		table_init(int ac, char **av, t_data *d);

// my own malloc, mutex, printf and thread manager function
int		mthread_manager(pthread_t *id, t_philos *philos, t_opcode opcode);
void	mmutex_manager(pthread_mutex_t *mtx, t_opcode opcode);
void	msem_manager(sem_t *sem, t_opcode opcode);

// void	*mmalloc(size_t bytes);
void	msg_action(t_philos *philo, int id, long timestamp, t_eatopcode opcode);

// getters and setters
void	set_bool(sem_t *sem, bool value, bool *location);
bool	get_bool(sem_t *sem, bool *location);
void	set_long(sem_t *sem, long value, long *location);
long	get_long(sem_t *sem, long *location);

// time management
long	time_getter(void);
void	wait_func(long time_to_wait, t_philos *philo);
void	wait_func_bis(t_philos *philo);
void	odd_thinking(t_philos	*philo);

// dinner
void	*diner_management(void *data);
void	eating(t_philos *philo);
void	sleeping(t_philos *philo);
void	thinking(t_philos *philo);
void	mutex_even_philo(t_philos	*philo);
void	mutex_odd_philo(t_philos *philo);
void	table(t_data *d);
void	one_philo(t_philos *philo);

// end of the dinner
int		dead_checker(t_data *d, int i);
int		end_of_simulation(t_data *d);
int		full_checker(t_data *d, int i);
int		clean(t_data *d);



#endif