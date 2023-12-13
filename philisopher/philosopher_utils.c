/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:08 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/13 11:45:12 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

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
	return (nb * signe);
}

void	msg_action(int id, long timestamp, t_eatopcode opcode)
{
	if (opcode == EAT)
		printf("%ld %d is eating\n", timestamp / 1000, id);
	else if (opcode == DIE)
		printf("%ld %d died\n", timestamp / 1000, id);
	else if (opcode == SLEEP)
		printf("%ld %d is sleeping\n", timestamp / 1000, id);
	else if (opcode == FORK)
		printf("%ld %d has taken a fork\n", timestamp / 1000, id);
	else if (opcode == THINK)
		printf("%ld %d is thinking\n", timestamp / 1000, id);
	else
		msg_exit("Message wrong opcode");
}

void	end_simulation(t_philos *philo)
{
	if (get_bool(philo->data->data_lock, philo->data->end))
		exit(-1);
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

void	wait_func_bis(t_philos *philo)
{
	mmutex_manager(&philo->data->dead_lock, LOCK);
	if (!get_bool(philo->data->data_lock, philo->data->end))
	{
		msg_action(philo->n, time_getter() - philo->data->start, DIE);
		set_bool(philo->data->data_lock, true, &philo->data->end);
	}
	mmutex_manager(&philo->data->dead_lock, UNLOCK);
	exit(-1);
}
