/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/10 19:48:55 by loris            ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct s_timer
{
	long	s;
	long	e;
	long	t;
	long	d;
}	t_timer;

typedef struct s_philos
{
	pthread_t id;
	int				n;
	long			time_left;
	pthread_mutex_t	previous_fork;
	pthread_mutex_t	next_fork;
	int				meal_count;
	t_data			*data;
} t_philos;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

struct s_data
{
	bool			end;
	bool			allthread_creat;
	int				n_o_p;
	t_philos		*philo;
	t_timer 		timer;
	t_fork			*fork;
	pthread_mutex_t	data_lock;
};

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
void	msg_exit(char *str);

// initialisation
void	initialisation(int ac, char **av, t_data *d);
void 	parsing(int ac, char **av, t_data *d);
int		ft_atoi(const char *nptr);

// my own malloc, mutex and thread manager function
void	mthread_manager(pthread_t id, t_philos *philos, t_opcode opcode);
void	mmutex_manager(pthread_mutex_t mtx, t_opcode opcode);
void	*mmalloc(size_t bytes);

// getters and setters
bool    set_bool(pthread_mutex_t lock, bool value, bool location);
bool    get_bool(pthread_mutex_t lock, bool location);
long    set_long(pthread_mutex_t lock, long value, long location);
long    get_long(pthread_mutex_t lock, long value, long location);

// time management
long	time_getter();
void	timer();


// dinner
void    diner_management(t_philos *philo);

#endif