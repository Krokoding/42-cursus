/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/13 14:29:38 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eating(t_philos *philo)
{
	if (philo->n % 2 == 0)
		mutex_even_philo(philo);
	else
		mutex_odd_philo(philo);
	set_long(philo->data->data_lock, philo->data->timer.d, &philo->time_left);
	msg_action(philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), EAT);
	philo->last_meal = time_getter() - philo->data->start;
	philo->meal_count++;
	wait_func(philo->data->timer.e, philo);
	mmutex_manager(&philo->next_fork->fork, UNLOCK);
	philo->next_fork->available = true;
	mmutex_manager(&philo->previous_fork->fork, UNLOCK);
	philo->previous_fork->available = true;
}

void	sleeping(t_philos *philo)
{
	msg_action(philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), SLEEP);
	wait_func(philo->data->timer.s, philo);
}

void	thinking(t_philos *philo)
{
	long	start;

	start = time_getter();
	if (philo->data->n_o_p % 2 != 0)
	{
		msg_action(philo->n, time_getter() - philo->data->start, THINK);
		wait_func(((philo->data->timer.e * 2) - philo->data->timer.s) * 0.42, philo);
		odd_thinking(philo);
	}
	else
	{
		if (philo->data->timer.e <= philo->data->timer.s)
			return ;
		else if (philo->data->timer.e > philo->data->timer.s)
		{
			msg_action(philo->n, time_getter() - philo->data->start, THINK);
			wait_func(philo->data->timer.s - philo->data->timer.e, philo);
			return ;
		}
	}
}

void	odd_thinking(t_philos *philo)
{
	while (!get_bool(philo->next_fork->fork, philo->next_fork->available) ||
			!get_bool(philo->previous_fork->fork, philo->previous_fork->available))
			wait_func(1001, philo);
}

void	dead_check(t_data *d)
{
	while ()
	{
		while (d.e)
	}
}