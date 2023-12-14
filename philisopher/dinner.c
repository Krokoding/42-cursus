/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/14 08:25:58 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*diner_management(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	while (!get_bool(philo->data->data_lock, philo->data->allthread_creat))
		;
	philo->data->start = time_getter();
	while (!get_bool(philo->data->data_lock, philo->data->end))
	{
		if (philo->data->max_meal != 0 && philo->meal_count
			== philo->data->max_meal)
			{
				philo->full = true;
				break ;
			}
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	mutex_odd_philo(t_philos *philo)
{
	if (philo->data->first_iteration)
		usleep(philo->data->timer.e - 5000);
	philo->data->first_iteration = 0;
	mmutex_manager(&philo->next_fork->fork, LOCK);
	philo->next_fork->available = false;
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), FORK);
	mmutex_manager(&philo->previous_fork->fork, LOCK);
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), FORK);
	philo->previous_fork->available = false;
}

void	mutex_even_philo(t_philos *philo)
{
	mmutex_manager(&philo->previous_fork->fork, LOCK);
	philo->previous_fork->available = false;
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), FORK);
	mmutex_manager(&philo->next_fork->fork, LOCK);
	philo->next_fork->available = false;
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), FORK);
}

// make a one philosopher dinner function
// make the programm stop when they have all eaten the right number of times