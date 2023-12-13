/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/12 17:10:23 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*diner_management(void *data)
{
	t_philos *philo;

	philo = (t_philos *)data;
	while (!get_bool(philo->data->data_lock, philo->data->allthread_creat))
		;
	philo->data->start = time_getter();
	while (!get_bool(philo->data->data_lock, philo->data->end))
	{
		// eating
		if (philo->data->max_meal != 0 && philo->meal_count == philo->data->max_meal)
			break;
		eating(philo);
		// sleeping
		sleeping(philo);
		// thinking
		thinking(philo);
	}
	return (NULL);
}
void	mutex_odd_philo(t_philos *philo)
{
	usleep(200);
	mmutex_manager(&philo->next_fork->fork, LOCK);
	
	philo->next_fork->available = 0;

	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), FORK);
		
	mmutex_manager(&philo->previous_fork->fork, LOCK);

	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), FORK);

	philo->previous_fork->available = 0;
}

void	mutex_even_philo(t_philos *philo)
{
	mmutex_manager(&philo->previous_fork->fork, LOCK);

	philo->previous_fork->available = 0;
	
	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), FORK);

	mmutex_manager(&philo->next_fork->fork, LOCK);

	philo->next_fork->available = 0;

	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), FORK);
}