/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/14 10:02:00 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
*	Function called by every thread.
*	Call the functions eat sleep and think
*	while end is true or all philo have eaten max meal
*/

void	*diner_management(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	while (!get_bool(philo->data->data_lock, philo->data->allthread_creat))
		;
	philo->data->start = time_getter();
	while (!get_bool(philo->data->data_lock, philo->data->end))
	{
		eating(philo);
		if (philo->data->max_meal != 0 && philo->meal_count
			== philo->data->max_meal)
		{
			philo->full = true;
			break ;
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

/*
*	The philos eat alternate if they are even or odd,
*	the "even" philo eat first to have all the forks
*	on the first iteration a time is set to synchronize them
*	and have no deadlock
*/

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