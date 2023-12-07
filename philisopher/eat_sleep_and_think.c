/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:13 by loris             #+#    #+#             */
/*   Updated: 2023/12/07 11:29:25 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int thinki_time(t_data *data, double time)
{
	if (data[-data->philosophers_num].dead == 1)
			return (0);
	if (data->philosophers_num == (data->number_of_philosopher - 1))
	{
		if (data->fork_indic == 1 || data[-data->philosophers_num].fork_indic == 1)
			printf("%d %d is thinking\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	else
	{
		if (data->fork_indic == 1 || data[1].fork_indic == 1)
			printf("%d %d is thinking\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	while (data->fork_indic == 1 || data[1].fork_indic == 1)
	{
		if (!time_or_die(data, 1000, 1))
			return (0);
		if (data[-data->philosophers_num].dead == 1)
			return (0);
		usleep(1000);
		data->time_left -= 1000;
	}
	return (1);
}

int slipi_time(t_data *data)
{
	if (data[-data->philosophers_num].dead == 1)
		return (0);
	if (!time_or_die(data, data->timer.sleep, 0))
		return (0);
	printf("%d %d is sleeping\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->time_left -= data->timer.sleep;
	usleep(data->timer.sleep);
	return (1);
}

int	eating_time(t_data *data)
{
	if (data[-data->philosophers_num].dead == 1)
		return (0);
	pthread_mutex_lock(&data->fork);
	data->fork_indic = 1;
	printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
	{
		pthread_mutex_lock(&data[1].fork);
		data[1].fork_indic = 1;
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	else
	{
		pthread_mutex_lock(&data[-(data->number_of_philosopher - 1)].fork);
		data[-(data->number_of_philosopher - 1)].fork_indic = 1;
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	printf("%d %d is eating\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->timer.start_eat = time_management() - data->start_time;
	data->time_left = data->timer.die;
	if (!time_or_die(data, data->timer.eat, 2))
		return (0);
	usleep(data->timer.eat);
	data->time_left -= data->timer.eat;
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
	{
		pthread_mutex_unlock(&data[1].fork);
		data[1].fork_indic = 0;
	}
	else
	{
		pthread_mutex_unlock(&data[-(data->number_of_philosopher - 1)].fork);
		data[-(data->number_of_philosopher - 1)].fork_indic = 0;
	}
	pthread_mutex_unlock(&data->fork);
	data->fork_indic = 0;
	return (1);
}
