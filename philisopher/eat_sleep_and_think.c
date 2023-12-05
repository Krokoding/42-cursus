/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:13 by loris             #+#    #+#             */
/*   Updated: 2023/12/05 14:12:14 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int thinki_time(t_data *data, double time)
{
	unsigned int i;

	i = (unsigned int)time;
	printf("%d %d is thinking\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->time_left -= time;
	usleep(i);
	return (1);
}

int slipi_time(t_data *data)
{
	if (!time_or_die(data, data->timer.sleep))
	{
		return (0);
	}
	printf("%d %d is sleeping\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->time_left -= data->timer.sleep;
	usleep(data->timer.sleep);
	return (1);
}

int	eating_time(t_data *data)
{
	pthread_mutex_lock(&data->fork);
	printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
	{
		pthread_mutex_lock(&data[1].fork);
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	else
	{
		pthread_mutex_lock(&data[-(data->number_of_philosopher - 1)].fork);
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	printf("%d %d is eating\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->timer.start_eat = time_management() - data->start_time;
	data->time_left = data->timer.die;
	usleep(data->timer.eat);
	data->time_left -= data->timer.eat;
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
		pthread_mutex_unlock(&data[1].fork);
	else
		pthread_mutex_unlock(&data[-(data->number_of_philosopher - 1)].fork);
	pthread_mutex_unlock(&data->fork);
	return (1);
}
