/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/04 14:08:21 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_struct
{
	double	sleep;
	double	eat;
	double	think;
	double	die;
	double	start_eat;
}	t_time;

typedef struct s_sstruct
{
	int				philosophers_num;
	double			start_time;
	t_time			timer;
	pthread_mutex_t fork;
	int				number_of_philosopher;
	double			time_left;
}   t_data;


int 	thinki_time(t_data *data, double time);
int 	slipi_time(t_data *data);
void	*philo_action(void *data);
double	time_management(void);
int		table(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep);
int		eating_time(t_data *data);
int		odd_philosopher(t_data *data);
int		even_philosopher(t_data *data);
int		time_or_die(t_data *data, double time);
double	time_to_think_calculator(t_data *data);
int		even_odd_manager(t_data *data);

#endif