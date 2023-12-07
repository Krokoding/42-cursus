/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/07 10:36:24 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct	s_struct
{
	double	sleep;
	double	eat;
	double	think;
	double	die;
	double	start_eat;
}	t_time;

typedef struct	s_sstruct
{
	int				philosophers_num;
	double			start_time;
	t_time			timer;
	pthread_mutex_t fork;
	pthread_mutex_t lock;
	int				dead;
	int				number_of_philosopher;
	double			time_left;
	int				fork_indic;
}	t_data;

int		thinki_time(t_data *data, double time);
int		slipi_time(t_data *data);
void	*philo_action(void *data);
double	time_management(void);
int		table(t_data *data);
int		eating_time(t_data *data);
int		odd_philosopher(t_data *data);
int		even_philosopher(t_data *data);
int		time_or_die(t_data *data, double time, int action);
double	time_to_think_calculator(t_data *data);
int		even_odd_manager(t_data *data);
t_data	*init(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep, t_data *data);
int		processus_for_even_philo(t_data *data, int i);
int		first_rotation_even_philosopher(t_data *data);
int		set_die_indicator(t_data *data);
int		ft_atoi(const char *nptr);

#endif