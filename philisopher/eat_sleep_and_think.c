/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/11 13:55:47 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating(t_philos *philo)
{
	//	reset time
	set_long(philo->data->data_lock, philo->data->timer.d, philo->time_left);
	//	write message
	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), EAT);
	//	upgrade meal
	philo->meal_count++;
	//	usleep and -timer to eat
	wait_func(philo->data->timer.e, philo);
	mmutex_manager(philo->next_fork.fork, UNLOCK);
	philo->next_fork.available = 1;
	mmutex_manager(philo->previous_fork.fork, UNLOCK);
	philo->previous_fork.available = 1;
}

void	sleeping(t_philos *philo)
{
	// write message
	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), SLEEP);
	// usleep
	wait_func(philo->data->timer.s, philo);
}

void	thinking(t_philos *philo)
{
	long	start;

	start = time_getter();
	// message
	if (philo->next_fork.available && philo->previous_fork.available)
		return;
	while (!philo->next_fork.available || !philo->previous_fork.available)
	{
		usleep(1000);
		philo->time_left -= 1;
		if (philo->time_left <= 0)
		{
			philo->data->end = 1;
			msg_action(philo->n, (time_getter() - start), DIE);
			exit(-1);
		}
	}
}
