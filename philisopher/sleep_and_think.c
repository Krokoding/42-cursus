/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:13 by loris             #+#    #+#             */
/*   Updated: 2023/12/05 13:13:01 by lkary-po         ###   ########.fr       */
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
	// printf("time to sleep = %lf\n", data->timer.sleep);
	usleep(data->timer.sleep);
	return (1);
}