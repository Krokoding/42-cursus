/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 15:18:38 by loris            ###   ########.fr       */
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
	while (!get_bool(&philo->data->data_lock, &philo->data->allthread_creat))
		;
	set_long(&philo->data->data_lock, time_getter(), &philo->data->start);
	if (philo->data->n_o_p == 1)
		one_philo(philo);
	else
	{
		while (!get_bool(&philo->data->data_lock, &philo->data->end))
		{
			eating(philo);
			if (philo->data->max_meal != 0 && philo->meal_count
				== philo->data->max_meal)
			{
				set_bool(&philo->data->data_lock, true, &philo->full);
				break ;
			}
			sleeping(philo);
			thinking(philo);
		}
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
	if (get_long(&philo->data->data_lock, &philo->data->first_iteration))
		usleep(philo->data->timer.e - 5000);
	set_long(&philo->data->data_lock, 0, &philo->data->first_iteration);
	mmutex_manager(&philo->next_fork->fork, LOCK);
	set_bool(&philo->data->data_lock, false, &philo->next_fork->available);
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), FORK);
	mmutex_manager(&philo->previous_fork->fork, LOCK);
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), FORK);
	set_bool(&philo->data->data_lock, false, &philo->previous_fork->available);
}

void	mutex_even_philo(t_philos *philo)
{
	mmutex_manager(&philo->previous_fork->fork, LOCK);
	set_bool(&philo->data->data_lock, false, &philo->previous_fork->available);
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), FORK);
	mmutex_manager(&philo->next_fork->fork, LOCK);
	set_bool(&philo->data->data_lock, false, &philo->next_fork->available);
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), FORK);
}

void	one_philo(t_philos *philo)
{
	mmutex_manager(&philo->previous_fork->fork, LOCK);
	msg_action(philo, philo->n, time_getter() - philo->data->start, FORK);
	wait_func(philo->data->timer.d, philo);
	mmutex_manager(&philo->previous_fork->fork, UNLOCK);
}