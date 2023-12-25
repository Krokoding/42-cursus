/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/22 14:21:36 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

/*
*	Function called by every thread.
*	Call the functions eat sleep and think
*	while end is true or all philo have eaten max meal
*/
void	*diner_management(t_philos *philo)
{
	pthread_t thread_check;

	pthread_create(&thread_check, NULL, end_of_simulation, philo);
	pthread_detach(thread_check);
	set_long(philo->data->data_lock, time_getter(), &philo->data->start);
	if (philo->data->n_o_p == 1)
		one_philo(philo);
	else
	{
		while (!get_bool(philo->data->data_lock, &philo->data->end))
		{
			eating(philo);
			if ((philo->data->max_meal != 0 && philo->meal_count
				== philo->data->max_meal)) 
				break ;
			sleeping(philo);
			thinking(philo);
		}
	}
	// if (get_bool(philo->data->data_lock, &philo->data->end))
	// 	exit (1);
	exit (0);
}

/*
*	The philos eat alternate if they are even or odd,
*	the "even" philo eat first to have all the forks
*	on the first iteration a time is set to synchronize them
*	and have no deadlock
*/
void	mutex_odd_philo(t_philos *philo)
{
	if (get_long(philo->data->data_lock, &philo->data->first_iteration))
		usleep(philo->data->timer.e - 5000);
	set_long(philo->data->data_lock, 0, &philo->data->first_iteration);
	msem_manager(philo->data->fork_sem, LOCK);
	set_bool(philo->data->data_lock, false, philo->next_fork);
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, &philo->data->start)), FORK);
	msem_manager(philo->data->fork_sem, LOCK);
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, &philo->data->start)), FORK);
	set_bool(philo->data->data_lock, false, philo->previous_fork);
}

void	mutex_even_philo(t_philos *philo)
{
	msem_manager(philo->data->fork_sem, LOCK);
	set_bool(philo->data->data_lock, false, philo->previous_fork);
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, &philo->data->start)), FORK);
	msem_manager(philo->data->fork_sem, LOCK);
	set_bool(philo->data->data_lock, false, philo->next_fork);
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, &philo->data->start)), FORK);
}

void	one_philo(t_philos *philo)
{
	msem_manager(philo->data->fork_sem, LOCK);
	msg_action(philo, philo->n, time_getter() - philo->data->start, FORK);
	wait_func(philo->data->timer.d);
	msem_manager(philo->data->fork_sem, UNLOCK);
}
