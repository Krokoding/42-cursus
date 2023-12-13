/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/12 16:22:04 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating(t_philos *philo)
{
	if (philo->n % 2 == 0)
		mutex_even_philo(philo);
	else
		mutex_odd_philo(philo);
	//	reset time
	set_long(philo->data->data_lock, philo->data->timer.d, &philo->time_left);
	//	write message
	msg_action(philo->n, (time_getter()
		- get_long(philo->data->data_lock, philo->data->start)), EAT);
	//	upgrade meal
	philo->meal_count++;
	//	usleep and -timer to eat
	wait_func(philo->data->timer.e, philo);
	mmutex_manager(&philo->next_fork->fork, UNLOCK);
	philo->next_fork->available = 1;
	mmutex_manager(&philo->previous_fork->fork, UNLOCK);
	philo->previous_fork->available = 1;
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
	if (philo->data->n_o_p % 2 != 0)
	{
		msg_action(philo->n, time_getter() - philo->data->start, THINK);
		wait_func(((philo->data->timer.e * 2) - philo->data->timer.s), philo);
	}
	else
	{
		if (philo->data->timer.e <= philo->data->timer.s)
		{
			return;

		}
		else if (philo->data->timer.e > philo->data->timer.s)
		{
			msg_action(philo->n, time_getter() - philo->data->start, THINK);
			wait_func(philo->data->timer.s - philo->data->timer.e, philo);
			return;
		}
	}
}
