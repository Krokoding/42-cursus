/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_of_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:04:35 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/06 08:41:27 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	odd_philosopher(t_data *data)
{
	double	time_think;
	while (data[-data->philosophers_num].dead == 0)
	{
		printf("slipi_time = %f\n", data->timer.sleep);
		if (!slipi_time(data))
			return (0);
		time_think = time_to_think_calculator(data);
		printf("thinki_time = %f\n", time_think);
		if (time_think)
			thinki_time(data, time_think);
		eating_time(data);
	}
	return (1);
}

int	processus_for_even_philo(t_data *data, int i)
{
	double	time_think;

	if (i == 0 && data->philosophers_num == data->number_of_philosopher -1)
	{
		if (!first_rotation_even_philosopher(data))
			return (0);
	}
	i = 1;
	eating_time(data);
	// if (data->philosophers_num == 0)
	// 	printf("philo %d, time left after eat = %lf \n", data->philosophers_num, data->time_left);
	if (!slipi_time(data))
		return (0);
	// if (data->philosophers_num == 0)
	// 	printf("philo %d, time left after sleep = %lf \n", data->philosophers_num, data->time_left);
	time_think = time_to_think_calculator(data);
	if (!time_or_die(data, time_think))
		return (0);
	if (time_think > 0)
		thinki_time(data, time_think);
	// if (data->philosophers_num == 0)
	// 	printf("philo %d, time left after think = %lf \n", data->philosophers_num, data->time_left);
	return (1);
}

int	first_rotation_even_philosopher(t_data *data)
{
	double	time_think;

	if (!slipi_time(data))
		return (0);
	time_think = time_to_think_calculator(data);
	if (time_think > 0)
		thinki_time(data, time_think);
	return (1);
}

int	even_philosopher(t_data *data)
{
	double	time_think;
	int		i;

	i = 0;
	while (data[-data->philosophers_num].dead == 0)
	{
		if (!processus_for_even_philo(data, i))
			return (0);
		i = 1;
	}
	return (0);
}
