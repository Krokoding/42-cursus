/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 15:40:56 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_data	t_data;

typedef struct s_timer
{
	long	s;
	long	e;
	long	t;
	long	d;
}	t_timer;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	long			fork_id;
	bool			available;
}	t_fork;

typedef struct s_philos
{
	pthread_t		id;
	long			n;
	long			time_left;
	t_fork			*previous_fork;
	t_fork			*next_fork;
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
	long			n_o_p;
	long			start;
	t_philos		*philo;
	t_timer			timer;
	t_fork			*fork;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	data_lock;
	long			max_meal;
	long			first_iteration;
	pthread_mutex_t	no_eat_when_die;
	pthread_mutex_t	msg_lock;
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
// void	*mmalloc(size_t bytes);
void	msg_action(t_philos *philo, int id, long timestamp, t_eatopcode opcode);

// getters and setters
void	set_bool(pthread_mutex_t *lock, bool value, bool *location);
bool	get_bool(pthread_mutex_t *lock, bool *location);
void	set_long(pthread_mutex_t *lock, long value, long *location);
long	get_long(pthread_mutex_t *lock, long *location);

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