/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:08 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/18 16:33:45 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		signe;

	signe = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	if (nb >= 2147483647)
		return (0);
	return (nb * signe);
}

void	msg_action(t_philos *philo, int id, long timestamp, t_eatopcode opcode)
{
	mmutex_manager(&philo->data->msg_lock, LOCK);
	if (opcode == EAT && !get_bool(&philo->data->data_lock, &philo->data->end))
		printf("%ld %d is eating\n", timestamp / 1000, id);
	else if (opcode == DIE)
		printf("%ld %d died\n", timestamp / 1000, id);
	else if (opcode == SLEEP
		&& !get_bool(&philo->data->data_lock, &philo->data->end))
		printf("%ld %d is sleeping\n", timestamp / 1000, id);
	else if (opcode == FORK
		&& !get_bool(&philo->data->data_lock, &philo->data->end))
		printf("%ld %d has taken a fork\n", timestamp / 1000, id);
	else if (opcode == THINK
		&& !get_bool(&philo->data->data_lock, &philo->data->end))
		printf("%ld %d is thinking\n", timestamp / 1000, id);
	mmutex_manager(&philo->data->msg_lock, UNLOCK);
}

long	time_getter(void)
{
	long			time_in_ms;
	struct timeval	tv;

	if (-1 == gettimeofday(&tv, NULL))
		msg_exit("Gettimeofday error");
	time_in_ms = tv.tv_sec * 1000000;
	time_in_ms += tv.tv_usec;
	return (time_in_ms);
}

int	dead_checker(t_data *d, int i)
{
	if (!get_bool(&d->data_lock, &d->philo[i].full) && (time_getter()
			- get_long(&d->data_lock, &d->philo[i].last_meal)
			>= get_long(&d->data_lock, &d->timer.d)))
	{
		mmutex_manager(&d->dead_lock, LOCK);
		if (!get_bool(&d->data_lock, &d->end))
		{
			msg_action(d->philo, d->philo[i].n, time_getter() - d->start, DIE);
			set_bool(&d->data_lock, true, &d->end);
		}
		mmutex_manager(&d->dead_lock, UNLOCK);
		return (0);
	}
	return (1);
}

int	full_checker(t_data *d, int i)
{
	if (!get_bool(&d->data_lock, &d->philo[i].full))
		d->all_full = false;
	if (i == d->n_o_p - 1 && d->all_full == true)
	{
		set_bool(&d->data_lock, true, &d->end);
		return (0);
	}
	return (1);
}
