/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:08 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/06 12:35:27 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	time_or_die(t_data *data, double time, int action)
{
	double time_before_message;
	double	time_left;
	time_before_message = data->time_left;
	time_left = data->time_left;
	time_left -= time;
	if (time_left <= 0)
	{
		if (action == 1)
			printf("%d %d is thinking\n", (int)(time_management() - data->start_time), data->philosophers_num);
		if (action == 0)
			printf("%d %d is sleeping\n", (int)(time_management() - data->start_time), data->philosophers_num);
		if (action == 2)
			printf("%d %d is eating\n", (int)(time_management() - data->start_time), data->philosophers_num);
		usleep(time_before_message);
		set_die_indicator(data);
		printf("%d %d died\n", (int)(time_management() - data->start_time), data->philosophers_num);
		return (0);
	}
	return (1);
}

double	time_to_think_calculator(t_data *data)
{
	double	time_to_think;
	if (data->philosophers_num != data->number_of_philosopher - 1)
		time_to_think = (data->timer.eat / 1000) - ((time_management() - data->start_time) - data[1].timer.start_eat);
	else
		time_to_think = (data->timer.eat / 1000) - ((time_management() - data->start_time) - data[-1].timer.start_eat);
	time_to_think *= 1000;
	return (time_to_think);
}

double	time_management(void)
{
	struct timeval	tv;
	double			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000;
	time_ms += tv.tv_usec / 1000;
	return (time_ms);
}

int	set_die_indicator(t_data *data)
{
	data[-data->philosophers_num].dead = 1;
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	signe = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}
