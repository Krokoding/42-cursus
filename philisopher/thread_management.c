/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:32 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/05 14:09:39 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	table(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep)
{
	t_data		*data;
	pthread_t	*philosopher;
	int			i;

	data = malloc(sizeof(t_data) * number_of_philosopher);
	philosopher = malloc(sizeof(pthread_t) * number_of_philosopher);
	i = 0;
	init(number_of_philosopher, time_to_die, time_to_eat, time_to_sleep, data);
	while (i < number_of_philosopher)
	{
		pthread_mutex_init(&data[i].fork, NULL);
		pthread_create(&philosopher[i], NULL, philo_action, &data[i]);
		i++;
	}
	i = 0;
	while (i < number_of_philosopher)
	{
		pthread_join(philosopher[i], NULL);
		i++;
	}
	i = 0;
	while (i < number_of_philosopher)
		pthread_mutex_destroy(&data[i++].fork);
	free(data);
	free(philosopher);
}

void	*philo_action(void *data)
{
	double	start;
	t_data	*fata;
	double	end;
	int		next_close_phil;

	fata = (t_data *)data;
	if (!even_odd_manager(fata))
		return (0);
}

int	even_odd_manager(t_data *data)
{
	if (data->philosophers_num % 2 == 0)
		return (even_philosopher(data));
	if (data->philosophers_num % 2 != 0)
		return (odd_philosopher(data));
}