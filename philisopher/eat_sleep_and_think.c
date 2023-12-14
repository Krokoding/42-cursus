/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/14 08:32:46 by loris            ###   ########.fr       */
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
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), EAT);
	philo->last_meal = time_getter();
	philo->meal_count++;
	wait_func(philo->data->timer.e, philo);
	mmutex_manager(&philo->next_fork->fork, UNLOCK);
	philo->next_fork->available = true;
	mmutex_manager(&philo->previous_fork->fork, UNLOCK);
	philo->previous_fork->available = true;
}

void	sleeping(t_philos *philo)
{
	msg_action(philo, philo->n, (time_getter()
			- get_long(philo->data->data_lock, philo->data->start)), SLEEP);
	wait_func(philo->data->timer.s, philo);
}

void	thinking(t_philos *philo)
{
	long	start;

	start = time_getter();
	if (philo->data->n_o_p % 2 != 0)
	{
		msg_action(philo, philo->n, time_getter() - philo->data->start, THINK);
		odd_thinking(philo);
	}
	else
	{
		if (philo->data->timer.e <= philo->data->timer.s)
			return ;
		else if (philo->data->timer.e > philo->data->timer.s)
		{
			msg_action(philo, philo->n, time_getter() - philo->data->start, THINK);
			wait_func(philo->data->timer.s - philo->data->timer.e, philo);
			return ;
		}
	}
}

void	odd_thinking(t_philos *philo)
{
	wait_func(((philo->data->timer.e * 2) - philo->data->timer.s) * 0.42, philo);
	while (!philo->next_fork->available ||
			!philo->previous_fork->available)
			;
}

int	end_of_simulation(t_data *d)
{
	int	i;

	while (!get_bool(d->data_lock, d->end))
	{
		i = -1;
		while (++i < d->n_o_p)
		{
			if (!d->philo[i].full && (time_getter() - d->philo[i].last_meal >= d->timer.d))
			{
				mmutex_manager(&d->dead_lock, LOCK);
				if (!get_bool(d->data_lock, d->end))
				{
					msg_action(d->philo, d->philo[i].n, time_getter() - d->start, DIE);
					set_bool(d->data_lock, true, &d->end);
				}
				mmutex_manager(&d->dead_lock, UNLOCK);
				return (0);
			}
		}
	}
	return (0);
}

void	full_checker(t_philos *philo)
{
	bool	all_full;
	int		i;
	
	all_full = false;
	while (!all_full)
	{
		i = -1;
		while (++i < philo->data->n_o_p)
		{
			
		}
	}
}