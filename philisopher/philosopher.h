/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:05 by loris             #+#    #+#             */
/*   Updated: 2023/12/04 10:15:12 by loris            ###   ########.fr       */
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
}   t_data;


int 	think(unsigned int time_to_sleep, double start, int philosopher_num);
int 	slip(unsigned int time_to_sleep, double start, int philosopher_num);
void	*philo_action(void *data);
double	time_management(void);
int		table(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep);
int		eating_time(t_data *data, int time_eat);


#endif