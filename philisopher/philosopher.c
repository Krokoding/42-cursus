/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/05 14:28:46 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	table(11, 2500000, 2000000, 1000000);
	while (1);
	{
		if (data[-data->philosophers_num].dead == 1)
			return (0);
	}
}

int	init(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep, t_data *data)
{
	int	i;

	i = 0;
	data->dead = 0;
	while (i < number_of_philosopher)
	{
		data[i].start_time = time_management();
		data[i].time_left = time_to_die;
		data[i].timer.die = time_to_die;
		data[i].timer.eat = time_to_eat;
		data[i].timer.sleep = time_to_sleep;
		data[i].philosophers_num = i;
		data[i].number_of_philosopher = number_of_philosopher;
		i++;
	}
}


