/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_and_think.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/16 15:44:24 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
*	Lock both fork depend if even or not
*	Increment the meal count
*	Unlock the forks
*/

void	eating(t_philos *philo)
{
	if (philo->n % 2 == 0)
		mutex_even_philo(philo);
	else
		mutex_odd_philo(philo);
	set_long(&philo->data->data_lock, philo->data->timer.d, &philo->time_left);
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), EAT);
	set_long(&philo->data->data_lock, time_getter(), &philo->last_meal);
	philo->meal_count++;
	wait_func(get_long(&philo->data->data_lock, &philo->data->timer.e), philo);
	mmutex_manager(&philo->next_fork->fork, UNLOCK);
	set_bool(&philo->data->data_lock, true, &philo->next_fork->available);
	mmutex_manager(&philo->previous_fork->fork, UNLOCK);
	set_bool(&philo->data->data_lock, true, &philo->previous_fork->available);
}

/*
*	Print message and wait
*/

void	sleeping(t_philos *philo)
{
	msg_action(philo, philo->n, (time_getter()
			- get_long(&philo->data->data_lock, &philo->data->start)), SLEEP);
	wait_func(philo->data->timer.s, philo);
}

/*
*	if even, the to sleep is always the same : if time to e bigger than tts
*	think time = tts - tte
*	if odd, odd_thinking function
*/

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
			msg_action(philo, philo->n, time_getter()
				- philo->data->start, THINK);
			wait_func(philo->data->timer.s - philo->data->timer.e, philo);
			return ;
		}
	}
}

/*
*	automaticly sleep to prevent desynchronisation
*	then wait untill the both fork are available
*/

void	odd_thinking(t_philos *philo)
{
	wait_func(((get_long(&philo->data->data_lock, &philo->data->timer.e)
				* 2) - get_long(&philo->data->data_lock, &philo->data->timer.s))
		* 0.42, philo);
	while (!get_bool(&philo->data->data_lock, &philo->next_fork->available)
		|| !get_bool(&philo->data->data_lock, &philo->previous_fork->available))
			;
}

/*
*	check 2 things :
*		- if all philo are full
				block the printf
				set end to true
*		- if on philo died
				printf a message and block the printing for other thread
				set end to true
*	End the simulation if end is true
*/

int	end_of_simulation(t_data *d)
{
	int	i;

	while (!get_bool(&d->data_lock, &d->end))
	{
		d->all_full = true;
		i = -1;
		while (++i < d->n_o_p)
		{
			if (!dead_checker(d, i))
				return (0);
			if (!full_checker(d, i))
				return (0);
		}
	}
	return (0);
}
