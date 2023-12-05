/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:08 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/05 14:26:05 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	time_or_die(t_data *data, double time)
{
	double time_before_message;

	time_before_message = data->time_left;
	data->time_left -= time;
	if (data->time_left <= 0)
	{
		set_die_indicator(data);
		printf("%d %d is sleeping\n", (int)(time_management() - data->start_time), data->philosophers_num);
		usleep(time_before_message);
		printf("%d %d died\n", (int)(time_management() - data->start_time), data->philosophers_num);
		return (0);
	}
	return (1);
}

double	time_to_think_calculator(t_data *data)
{
	double	time_to_think;

	time_to_think = (data->timer.eat / 1000) - (data->timer.start_eat - (time_management() - data->start_time));
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