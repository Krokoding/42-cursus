/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/07 11:20:58 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data		*data;
	double		time_to_die;
	double		time_to_eat;
	double		time_to_sleep;

	time_to_die = ft_atoi(av[2]) * 1000;
	time_to_eat = ft_atoi(av[3]) * 1000;
	time_to_sleep = ft_atoi(av[4]) * 1000;
	data = malloc(sizeof(t_data) * atoi(av[1]));
	data = init(atoi(av[1]), time_to_die, time_to_eat, time_to_sleep, data);
	table(data);
}

t_data	*init(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep, t_data *data)
{
	int	i;

	i = 0;
	data->dead = 0;
	pthread_mutex_init(&data->lock, NULL);
	while (i < number_of_philosopher)
	{
		data[i].fork_indic = 0;
		data[i].start_time = time_management();
		data[i].time_left = time_to_die;
		data[i].timer.die = time_to_die;
		data[i].timer.eat = time_to_eat;
		data[i].timer.sleep = time_to_sleep;
		data[i].philosophers_num = i;
		data[i].number_of_philosopher = number_of_philosopher;
		i++;
	}
	return (data);
}


